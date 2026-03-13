# Tower Defense (Unreal Engine C++)

## Overview

This project is a **Tower Defense game developed in Unreal Engine using C++**.
The goal is to defend the player's **Core** from waves of enemies by strategically placing defensive towers.

The project focuses on **gameplay systems architecture**, including enemy behavior, tower mechanics, and resource management.

---

# Core Gameplay Mechanics

The main gameplay loop works as follows:

1. The player starts with a limited amount of **Energy**.
2. Energy is used to **build towers**.
3. Towers automatically **detect and attack enemies**.
4. Enemies move toward the **Core**.
5. If enemies reach the Core, it **takes damage**.
6. Destroyed enemies **reward energy** to the player.
7. The player loses if the **Core is destroyed**.
8. The player wins by **surviving all waves**.

---

# Main Systems

## Energy System

Managed by `TDGameState`.

Responsibilities:

- Store total player energy
- Spend energy when placing towers
- Reward energy when enemies are destroyed

Main functions:

```
SpendEnergy()
AddEnergy()
GetAvailableEnergy()
```

---

## Enemy System

Base class: `EnemyBase`

Responsibilities:

- Move toward the Core
- Receive damage from towers
- Reward the player when destroyed
- Damage the Core when reaching it

Main attributes:

```
MaxHealth
CurrentHealth
Speed
DamageToCore
RewardEnergy
```

---

## Core System

Class: `CoreBase`

Represents the **base the player must defend**.

Responsibilities:

- Store core health
- Receive damage from enemies
- Trigger Game Over when destroyed

---

## Tower System

Class: `TowerBase`

Responsibilities:

- Detect enemies in range
- Select a target
- Attack enemies automatically

Main attributes:

```
AttackRange
Damage
FireRate
EnergyCost
```

---

# Project Architecture

Game architecture overview:

```
GameMode
   │
   ├── WaveManager
   │        └── EnemyBase
   │
   ├── CoreBase
   │
   └── TDGameState
           ├── Energy System
           └── Resource Management
```

Interaction flow:

```
Tower → Enemy → Core
         │
         ▼
     GameState
```

---

# Technologies Used

- **Unreal Engine 5**
- **C++ Gameplay Programming**
- Unreal Gameplay Framework
  - GameMode
  - GameState
  - Actors
  - Character

---

# How to Run

1. Clone the repository

```
git clone https://github.com/OrlandoKFerreira/TowerDefense-Unreal.git
```

2. Open the `.uproject` file with Unreal Engine.

3. Generate project files if needed.

4. Compile the project.

---

# Development Roadmap

Planned systems:

- Wave Manager
- Enemy path system
- Tower placement system
- Tower upgrades
- UI for energy and waves
- Enemy variations (Fast, Tank, Boss)
- Visual effects and polish

---

# Author

Orlando Ferreira

Unreal Engine C++ learning project focused on gameplay systems and architecture.
