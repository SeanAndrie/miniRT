*This project has been created as part of the 42 curriculum by sgadinga, zsalih*

# miniRT — A Raytracer in C

## Description

miniRT is a ray tracing engine built from scratch in C as part of the 42 school curriculum. The goal is to render 3D scenes described in `.rt` scene files by simulating the physical behavior of light rays — tracing each pixel's ray from the camera into the scene, computing intersections with geometric objects, and applying lighting models to produce a realistic image.

The engine supports a full set of geometric primitives, advanced lighting with the complete Phong reflection model, and several bonus features including cone rendering, checkerboard patterns, multi-spot colored lights, and bump map texture support.

---

## Instructions

### Requirements

- Linux OS
- `cc` and `make`
- X11 development libraries (required by MiniLibX)

Install the required dependencies:

```bash
sudo apt update
sudo apt install build-essential libx11-dev libxext-dev zlib1g-dev
```

> Required for MiniLibX linking: -lXext -lX11 -lm -lz

### Compilation

Clone the repository and compile with:

```bash
make
```

To clean object files:

```bash
make clean
```

To fully clean (including the binary):

```bash
make fclean
```

### Execution

```bash
./minirt scene/<scene_file>.rt
```

**Example:**

```bash
./minirt scene/15_earth.rt
```

Scene files describe the camera, lights, and objects in the scene. They must follow the `.rt` format defined by the project specification (see [Scene Format documentation](docs/SCENE_FORMAT.md))

---

## Features

### Mandatory

- Support for geometric primitives: **sphere**, **plane**, and **cylinder**
- Accurate **ray–object intersections**, including correct handling of object interiors
- Object properties: 
  - Sphere: adjustable **diameter**
  - Cylinder: adjustable **diameter** and **height**
- Full **geometric transformations**:
  - Translation and rotation for objects, lights, and camera
  - *(excluding rotation for spheres and lights, as per subject constraints)*
- Lighting system:
  - **Ambient lighting** (ensuring no complete darkness)
  - **Diffuse lighting**
  - **Hard shadows**
  - Configurable light intensity (brightness)
- Scene rendering from .rt files following the project specification

### Bonus

- **Advanced lighting**
  - Full **Phong reflection model** (ambient + diffuse + specular)
  - Support for **multiple colored light sources**
- **Texturing**
  - **Checkerboard patterns** (procedural textures)
  - **Bump map textures** for surface detail via normal perturbation
- **Additional geometry**
  - **Cone** support (second-degree primitive beyond mandatory objects)


---

## Internal Libraries

- **libtensr** — custom math and geometry library  
  Provides vector operations, math utilities, and core structures used in the ray tracing engine.

- **libft** - foundational utility library  
Provides standard C functions and basic utilities used across the project.

Included as part of this repository.

---

## Documentation

For a deeper understanding of the project architecture and implementation details:

- [Architecture Overview](docs/ARCHITECTURE.md)
- [Rendering Pipeline](docs/RENDERING.md)
- [Scene File Format](docs/SCENE_FORMAT.md)
- [Threading Model](docs/THREADING.md)
- [User Interactive Settings](docs/INTERACTIVE.md)

---

## Resources

### Ray Tracing & Mathematics

- [Ray Tracing Gems (v1.9) — Haines et al.](https://www.realtimerendering.com/raytracinggems/unofficial_RayTracingGems_v1.9.pdf)  
  Comprehensive reference on ray tracing techniques, intersection math, and lighting models.

- [Khan Academy — Linear Algebra](https://www.khanacademy.org/math/linear-algebra)  
  Foundational reference for vectors, dot products, cross products, and matrix transformations — all essential to ray tracing.

- [The Cherno — Ray Tracing Series (YouTube)](https://www.youtube.com/watch?v=gfW1Fhd9u9Q&list=PLlrATfBNZ98edc5GshdBtREv5asFW3yXl)  
  Step-by-step ray tracing series covering the basics through practical implementation.

- [Sebastian Lague — Coding Adventures: Ray Tracing (YouTube)](https://www.youtube.com/watch?v=HDfxts9YbUA)  
  Visual walkthrough of ray tracing fundamentals with clear explanations.

- [LearnOpenGL — Normal Mapping](https://learnopengl.com/Advanced-Lighting/Normal-Mapping)  
  Reference for understanding and implementing bump map / normal map textures.

- [NumPy Reference](https://numpy.org/doc/stable/user/index.html)  
NumPy library reference manual, which inspired the design for the libtensr library.

