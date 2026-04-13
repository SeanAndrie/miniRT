# Scene File Format

## Overview

Scene files (`.rt`) define a 3D scene for miniRT to render. Each line specifies an element: ambient light, camera, lights, or objects.

## Syntax

```
# Comment lines start with #

<element_type> <parameters> [<options>]
```

## Element Types

### Ambient Light

```
A <ratio> <R,G,B>
```

| Parameter | Type | Range | Description |
|-----------|------|-------|-------------|
| ratio | float | 0-1 | Ambient intensity |
| R,G,B | int | 0-255 | RGB color |

**Example**:
```
A 0.2 255,255,255
```

### Camera

```
C <position> <orientation> <fov>
```

| Parameter | Type | Range | Description |
|-----------|------|-------|-------------|
| position | vec3 | any | Camera XYZ position |
| orientation | vec3 | normalized | Look direction |
| fov | float | 0-180 | Field of view (degrees) |

**Example**:
```
C 0,5,-20 0,-0.2,1 70
```

### Light

```
L <position> <ratio> <R,G,B>
```

| Parameter | Type | Range | Description |
|-----------|------|-------|-------------|
| position | vec3 | any | Light XYZ position |
| ratio | float | 0-1 | Brightness ratio |
| R,G,B | int | 0-255 | RGB color |

**Example**:
```
L 0,10,-10 0.8 255,255,255
```

### Sphere

```
sp <position> <radius> <R,G,B>
```

| Parameter | Type | Description |
|-----------|------|-------------|
| position | vec3 | Sphere center |
| diameter | float | Sphere radius |
| R,G,B | int | RGB color |

**Example**:
```
sp 0,0,10 6 255,50,50
```

### Plane

```
pl <position> <normal> <R,G,B>
```

| Parameter | Type | Description |
|-----------|------|-------------|
| position | vec3 | Point on plane |
| normal | vec3 | Plane normal (normalized) |
| R,G,B | int | RGB color |

**Example**:
```
pl 0,-3,0 0,1,0 100,100,100
```

### Cylinder

cy <position> <axis> <radius> <height> R,G,B>
```
```

| Parameter | Type | Description |
|-----------|------|-------------|
| position | vec3 | Base center |
| axis | vec3 | Height direction (normalized) |
| diameter | float | Cylinder radius |
| height | float | Cylinder height |
| R,G,B | int | RGB color |

**Example**:
```
cy 8,0,10 0,1,0 4 10 50,150,255
```

### Cone

```
co <apex> <axis> <height> <radius> <R,G,B>
```

| Parameter | Type | Description |
|-----------|------|-------------|
| apex | vec3 | Cone apex point |
| axis | vec3 | Height direction (normalized) |
| height | float | Cone height |
| radius | float | Base radius |
| R,G,B | int | RGB color |

**Example**:
```
co 0,5,0 0,1,0 10 4 255,100,100
```

## Optional Parameters

Optional parameters follow `|` separated:

```
<element> <params> | <option1>:<value1> <option2>:<value2>
```

### Texture Mapping

```
tx:<path>
```

Load an XPM texture file.

**Example**:
```
sp 0,0,0 2 255,255,255 | tx:textures/Earth.xpm
```

### Bump Mapping

```
bm:<path>
```

Load a bump map (XPM format). Creates surface detail via gradient.

**Example**:
```
sp 0,0,0 2 255,255,255 | bm:textures/Earth_Bump.xpm
```

### Checkerboard Pattern

```
cb:<scale>
```

Procedural checkerboard pattern.

**Example**:
```
pl 0,-1,0 0,1,0 255,255,255 | cb:2.0f
```

### Reflectivity

```
rf:<factor>
```

Surface reflectivity (0-1).

**Example**:
```
pl 0,-1,0 0,1,0 100,100,100 | rf:0.5f
```

### Specular Intensity

```
sc:<bool>
```

Enable specular highlights.

**Example**:
```
sp 0,0,10 6 255,50,50 | sc:true
```

## Complete Example

```rt
# 01_mandatory_basic.rt
# Tests: sphere, plane, cylinder — one of each, one light, ambient

A 0.2 255,255,255

C 0,5,-20 0,-0.2,1 70

L 0,10,-10 0.8 255,255,255

pl 0,-3,0 0,1,0 100,100,100 | rf:0.5f

sp 0,0,10 6 255,50,50

cy 8,0,10 0,1,0 4 10 50,150,255
```

## Example Scenes

| File | Features |
|------|---------|
| `01_mandatory_basic.rt` | Basic primitives |
| `03_ambient_only.rt` | Ambient lighting |
| `04_shadows.kt` | Shadow testing |
| `10_checkerboard.kt` | Procedural checkerboard |
| `11_specular.kt` | Specular highlights |
| `12_cone.kt` | Cone primitive |
| `15_earth.kt` | Texture + bump mapping |

## Validation

The parser validates:

- Vector components are within valid ranges
- Orientation vectors are normalized
- Colors are 0-255
- File has required elements (A, C, at least one object)

## Key Files

| File | Purpose |
|------|---------|
| `src/parse/core/parse_scene.c` | Main parser |
| `src/parse/elements/parse_*.c` | Element parsers |
| `src/parse/utils/scalar_in_range.c` | Validation |
