# Rendering Pipeline

## Overview

The rendering pipeline performs real-time raytracing with the following stages:

```
Scene Load → Camera Setup → Tile Creation → Ray Tracing → Shading → Display
```

## Core Data Structures

### t_ray

```c
typedef struct s_ray
{
    t_vec3    orig;   // Ray origin
    t_vec3    dir;    // Ray direction (normalized)
} t_ray;
```

### t_hit

```c
typedef struct s_hit
{
    float       u;         // UV coordinate U
    float       v;         // UV coordinate V
    float       t;         // Distance from ray origin
    enum e_surface loc;   // Hit location (side/top/bottom)
    t_ray       ray;       // Incident ray
    t_vec3      rgb;       // Object color
    t_object   *obj;      // Hit object
    t_vec3      point;     // Hit point
    t_vec3      normal;   // Surface normal
    t_vec3      tangent;  // Tangent for normal mapping
    t_vec3      bitangent;// Bitangent for normal mapping
} t_hit;
```

## Pipeline Stages

### 1. Tile Creation

The framebuffer is divided into tiles for parallel processing:

```
src/render/tile/tile_create.c
```

- Creates a viewport-sized tensor slice for each tile
- Stores ray directions for all pixels in the tile
- Default tile size: 16x16 pixels (256 total tiles)

### 2. Ray Generation

```
src/render/ray/ray_create.c
src/scene/elements/camera/camera_rdir.c
```

For each pixel, a ray is created from the camera origin through the pixel:

1. Compute normalized device coordinates (NDC)
2. Transform to camera basis (up, right, forward)
3. Compute ray direction using camera FOV

### 3. Intersection Testing

```
src/render/elements/isect/*.c
```

Tests ray against each object in the scene.

**Sphere** (`isect_sphere.c`):
- Solves quadratic equation: |O + tD - C|² = r²
- Returns smallest positive t

**Plane** (`isect_plane.c`):
- Computes t where ray intersects plane: (P - O) · n / D · n
- Checks for valid t > epsilon

**Cylinder** (`isect_cylinder.c`):
- Solves quadratic for infinite cylinder
- Caps check (top/bottom) if hit found
- Returns `t_surface` enum (SURF_SIDE, SURF_TOP, SURF_BOT)

**Cone** (`isect_cone.c`):
- Solves quadratic with apex tip handling
- Computes k2, k coefficients for cone geometry

### 4. Normal Calculation

```
src/render/elements/normal/*.c
```

**Sphere**:
```c
t_vec3 normal_sphere(t_vec3 point, t_sphere *sp)
{
    return vec3_normalize(vec3_sub(point, sp->center));
}
```

**Plane**:
- Uses plane normal (flipped if ray hits from behind)

**Cylinder/Cone**:
- Computes normal based on hit location (side vs caps)
- Applies object rotation transforms

### 5. UV Mapping

```
src/render/elements/uv/*.c
```

Maps hit point to texture coordinates:

- **Sphere**: Spherical projection
- **Plane**: Planar projection based on hit coordinates
- **Cylinder**: Cylindrical projection

### 6. Shading

```
src/render/shade/shade_apply.c
```

Combines multiple lighting components:

```c
t_vec3 shade_apply(t_scene *scene, t_hit *hit)
{
    if (hit->obj->opt.reflectivity > 0.0f)
        return render_reflect_hit(hit, scene, 3);  // 3 bounce depth
    return shade_color(scene, hit);
}
```

**Shading Components**:

| Component | Function | Description |
|-----------|----------|-------------|
| Ambient | `shade_ambient` | Base illumination |
| Diffuse | `shade_diffuse` | Lambertian diffuse |
| Specular | `shade_specular` | Blinn-Phong specular |
| Checker | `shade_checker` | Procedural checkerboard |

**Diffuse (Lambertian)**:
```c
t_vec3 shade_diffuse(float ratio, t_vec3 light_rgb, t_hit *hit, t_vec3 L_hat)
{
    float dotNL = vec3_dot(hit->normal, L_hat);
    float intensity = fmaxf(0, dotNL) * ratio;
    return vec3_mul(hit->rgb, light_rgb, intensity);
}
```

**Specular (Blinn-Phong)**:
```c
// Half vector: normalize(light_dir + view_dir)
// Intensity: pow(max(0, dot(normal, half)), shine_factor)
```

### 7. Reflection

Recursive ray tracing for reflective surfaces:

1. Compute reflected direction: `R = D - 2(D·N)N`
2. Offset origin by small epsilon to prevent self-intersection
3. Trace reflected ray (depth decrements each bounce)
4. Blend with surface color using reflectivity factor

### 8. Display Blit

```
src/display/frame/frame_blit.c
```

- Converts floating-point RGB to 8-bit color
- Copies buffer to X11 image
- Updates window

## Key Files

| File | Purpose |
|------|---------|
| `src/render/core/render.c` | Main render loop |
| `src/render/core/render_trace.c` | Ray-scene intersection |
| `src/render/elements/isect/*.c` | Intersection tests |
| `src/render/elements/normal/*.c` | Normal calculation |
| `src/render/shade/shade_*.c` | Lighting models |
| `src/display/frame/frame_blit.c` | Display update |