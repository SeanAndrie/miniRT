# Code Architecture

## Directory Structure

```
miniRT/
├── src/
│   ├── main.c                    # Entry point
│   ├── parse/                   # Scene file parsing
│   ├── scene/                   # Scene management
│   ├── objects/                 # Object management
│   ├── render/                  # Raytracing core
│   ├── context/                 # Interactive app context
│   ├── display/                 # X11 display management
│   └── texture/                 # Texture handling
├── includes/
│   ├── miniRT.h                 # Main include
│   ├── config.h                 # Configuration constants
│   ├── core/                    # Core headers
│   ├── elements/                # Element headers
│   └── setup/                   # Setup headers
├── scenes/                      # Example .rt files
├── textures/                   # XPM texture files
└── Makefile
```

## Module Overview

### 1. Parse Module (`src/parse/`)

Responsible for parsing `.rt` scene files.

| File | Purpose |
|------|---------|
| `parse/core/parse_scene.c` | Main parser entry |
| `parse/core/parse_data.c` | Token parsing |
| `parse/core/parse_vector.c` | Vector parsing |
| `parse/core/parse_orient.c` | Orientation parsing |
| `parse/core/parse_scalar.c` | Scalar parsing |
| `parse/elements/parse_*.c` | Element-specific parsing |
| `parse/utils/token_free.c` | Memory cleanup |

### 2. Scene Module (`src/scene/`)

Manages scene data structures.

| File | Purpose |
|------|---------|
| `scene/core/scene_init.c` | Scene creation |
| `scene/elements/camera/*.c` | Camera setup |
| `scene/elements/light/*.c` | Light management |

### 3. Objects Module (`src/objects/`)

Object (3D shape) management.

| File | Purpose |
|------|---------|
| `objects/core/obj_alloc.c` | Object allocation |
| `objects/core/obj_append.c` | List management |
| `objects/shapes/obj_*.c` | Shape initialization |

### 4. Render Module (`src/render/`)

Core raytracing engine.

| Subdirectory | Purpose |
|------------|---------|
| `render/core/` | Main render loop |
| `render/elements/isect/` | Intersection tests |
| `render/elements/normal/` | Normal calculation |
| `render/elements/uv/` | UV mapping |
| `render/ray/` | Ray operations |
| `render/shade/` | Shading models |
| `render/pool/` | Threading pool |
| `render/tile/` | Tile management |

### 5. Context Module (`src/context/`)

Interactive application state and event handling.

| Subdirectory | Purpose |
|------------|---------|
| `context/core/` | App initialization/loop |
| `context/hooks/handle/` | Event handlers |
| `context/hooks/dispatch/` | Action dispatch |
| `context/hooks/tween/` | Animation tweens |
| `context/utils/` | Utility functions |
| `context/interface/` | UI rendering |

### 6. Display Module (`src/display/`)

X11 window management.

| File | Purpose |
|------|---------|
| `display/core/display_init.c` | Window creation |
| `display/frame/frame_init.c` | Framebuffer setup |
| `display/frame/frame_blit.c` | Display update |

### 7. Texture Module (`src/texture/`)

Texture loading and manipulation.

| File | Purpose |
|------|---------|
| `texture/core/texture_load.c` | XPM loading |
| `texture/core/texture_color.c` | Color sampling |
| `texture/bump/*.c` | Bump mapping |

## Key Data Structures

### t_scene

```c
typedef struct s_scene
{
    t_ambient  amb;      // Ambient light
    t_camera  cam;       // Camera
    t_light  *lights;    // Light list
    t_object *objects;   // Object list
    t_array   obj_view;   // Object array view
    t_array   lgt_view;  // Light array view
} t_scene;
```

### t_object

```c
typedef struct s_object
{
    enum e_type   type;   // Object type
    union u_data  data;    // Shape data (sphere/plane/cylinder/cone)
    t_options    opt;     // Rendering options
    t_object    *next;    // Next object in list
} t_object;
```

### t_options

```c
typedef struct s_options
{
    float     cb_scale;       // Checkerboard scale
    float     reflectivity;   // Reflectivity (0-1)
    char     *texture_path;   // Texture file path
    t_texture *texture;       // Loaded texture
    char     *bump_path;      // Bump map path
    t_texture *bump_texture; // Loaded bump map
    char     *specularity;   // Specular properties
} t_options;
```

### t_camera

```c
typedef struct s_camera
{
    float   fov;           // Field of view
    t_rdir  rdir;           // Ray directions
    t_vec3  point;          // Camera position
    t_basis basis;         // Camera basis vectors
    t_coord coords;        // Coordinate ranges
    t_bool allocd;        // Allocated flag
} t_camera;
```

### t_context

```c
typedef struct s_context
{
    t_pool    pool;       // Render thread pool
    t_display *disp;     // Display connection
    t_scene  *scene;     // Current scene
    t_object *s_obj;      // Selected object
    t_light  *s_lgt;      // Selected light
    char     *fname;      // Scene filename
    size_t   next_i;      // Next object index
    t_bool   dirty;       // Needs re-render
    t_bool   extend;      // Extend mode
    t_bool   property;    // Property mode
    t_bool   show_ui;     // Show UI
    t_tween  tw_trans;   // Translation tween
    t_tween  tw_rotate;   // Rotation tween
} t_context;
```

## Header Organization

| Header | Contains |
|--------|----------|
| `includes/miniRT.h` | Main include, includes all |
| `includes/config.h` | Configuration constants |
| `includes/core/context.h` | Context and events |
| `includes/core/render.h` | Rendering structures |
| `includes/elements/object.h` | Object definitions |
| `includes/elements/scene.h` | Scene definitions |
| `includes/setup/parse.h` | Parser declarations |
| `includes/setup/display.h` | Display declarations |