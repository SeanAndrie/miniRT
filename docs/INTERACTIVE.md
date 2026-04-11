# Interactive Controls

## Overview

miniRT provides real-time interactive controls for manipulating the scene. When running, press keys or use the mouse to modify camera position, selected objects, or lights.

## Keyboard Controls

### Translation (Normal Mode)

| Key | Action |
|-----|-------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `Q` | Move up |
| `E` | Move down |

### Rotation (Extend Mode)

Hold `Shift` to enable rotation mode:

| Key | Action |
|-----|-------|
| `W` / `S` | Pitch up/down (rotate around right axis) |
| `A` / `D` | Roll left/right (rotate around up axis) |
| `Q` / `E` | Yaw left/right (rotate around forward axis) |

### Property Mode

Press `P` to toggle property mode. In property mode, the following keys modify the selected object's properties:

| Key | Action |
|-----|-------|
| `R` | Modify object-specific property |
| `H` | Modify object-specific property |
| `T` | Modify object-specific property |

The R, H, T keys behave differently based on the selected object type:

| Object | R key | H key | T key |
|--------|-------|-------|-------|
| Sphere | Modify radius | - | - |
| Cylinder | Modify radius | Modify height | - |
| Cone | - | Modify height | Modify theta |

### Other Controls

| Key | Action |
|-----|-------|
| `P` | Toggle property mode |
| `Shift+L` | Cycle through lights |
| `U` | Toggle UI overlay |
| `R` | Reset scene to initial state |
| `ESC` | Exit application |

**Note**: When not in property mode, `R` resets the scene.

## Mouse Controls

| Button | Action |
|--------|--------|
| Left Click | Select object at cursor |
| Right Click | Deselect and select camera |

## Modes

### Normal Mode (Default)

Translation controls move the selected object (or camera if no object selected) using WASD+QE keys.

### Extend Mode (Shift Held)

When Shift is held, WASD+QE keys rotate the selected object or camera using Rodrigues' rotation formula around the camera's basis vectors.

### Property Mode (P Toggled)

When property mode is enabled, R/H/T keys modify specific properties of the selected object based on its type. This mode does not affect translation or rotation.

## Implementation

### Event Handling

```
src/context/
├── hooks/handle/
│   ├── handle_keypress.c    # Key down events
│   ├── handle_keyrelease.c  # Key up events
│   └── handle_mousepress.c # Mouse button events
├── hooks/dispatch/
│   ├── dispatch_translate.c   # Movement dispatch
│   ├── dispatch_rotate.c  # Rotation dispatch
│   └── dispatch_property.c  # Property changes
└── hooks/tween/
    ├── tween_lerp_update.c  # Linear interpolation
    └── tween_slerp_update.c # Spherical interpolation
```

### Tween System

Smooth animations using linear interpolation (LERP) and spherical LERP (SLERP):

```c
typedef struct s_tween
{
    t_vec3 *curr;       // Current position
    t_vec3 target;     // Target position
    t_bool (*update)(t_tween *tw, float t);  // Interpolation function
} t_tween;
```

### Rodrigues Rotation

Rotation uses the Rodrigues rotation formula:

```
v_rot = v*cos(θ) + (k × v)*sin(θ) + k*(k·v)*(1 - cos(θ))
```

where `k` is the rotation axis and `θ` is the rotation angle.

## Configuration

Tweaking parameters in `includes/config.h`:

```c
#define TWEEN_FACTOR  0.2f   // Interpolation factor
#define TRANS_SPEED  1.2f   // Translation speed
#define ROTATE_ANGLE 0.2f    // Rotation angle per key
#define PROP_INCREMENT 0.5f   // Property increment
```