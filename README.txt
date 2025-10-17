# NASA Satellite Simulation Project
# To see the project in action, look at Simulation_demo.mov

This project was developed using the **NASA Trick Simulation Toolkit** on a Unix environment.  
It simulates the orbital motion of a satellite around Earth using Newtonian gravitational physics.

---

Files Overview

- Initializes satellite position, velocity, and acceleration vectors
- Calculates gravitational and centripetal forces
- Integrates system state variables over time
- Logs and visualizes orbital behavior

---

Files Description

| File | Description |
| `satellite_init.cpp` | Defines initial parameters, integrator logic, and differential equations for the simulation 
| `S_define` | Declares and registers simulation objects and data models 
| `S_overrides.mk` | Makefile overrides for Trick build configuration 
| `satellite.dr` | Data recording configuration script 
| `realtime.py` | Sets up frame rate and runtime control for Trick simulation 

---

🧩 Requirements
- Unix/Linux environment  
- [NASA Trick Simulation Toolkit](https://github.com/nasa/trick)  
- C++ compiler (GCC/Clang)

---

Build & Run (on Unix)

```bash
make
./S_main_${USER}_SIM_satellite.exe

** NOTE **
This project was developed on a Unix based environment using the NASA Trick simulation toolkit.
It requires Trick and a Unix-like toolchain to build/run. This repository is for **source & documentation ONLY**
It may not compile or run on a windows based system, and not guaranteed to be runnable without the correct environment, as this was built on a unique machine.
