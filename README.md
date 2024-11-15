# Dungeons and Dragons Console Game

This project is a C++ console-based game inspired by Dungeons & Dragons. Players create a hero by choosing attributes, background, race, class, and abilities. The game involves navigating through rooms, interacting with objects, and fighting enemies until all objectives are achieved or all enemies are defeated.

## Table of Contents
1. [Project Structure](#project-structure)
2. [Game Rules](#game-rules)
3. [How to Play](#how-to-play)
4. [Features](#features)

---

## Project Structure

The project is organized into a directory structure to separate the game components, character classes, and environment elements. Here are the main directories and files:

- **Character**: Contains the base definitions for characters, including abilities (`Ability.h`), attributes (`Atribute.h`), and builders for characters (`CharacterBuilder.h`, `EnemyBuilder.h`, `MainCharacterBuilder.h`).
- **Clasa**: (`IClasa.h`) Defines the various character classes (`CArcher.h`, `CFighter.h`, `CWizard.h`), with a class factory for creating new classes (`ClasaFactory.h`).
- **Environment**: Manages the game environment, including objects (`Object.h`), rooms (`Room.h`), and connections between rooms (`Way.h`).
- **Rasa**: (`IRasa.h`) Files defining available races (, `CElf.h`, `CGoblin.h`, `CHuman.h`) and a factory for creating races (`RasaFactory.h`).
- **Other Files**:
  - `Dice.h`: Implements the dice mechanics for success or failure in actions.
  - `DungeonMaster.h`: The main game manager that handles character creation, map initialization, and the adventure flow.
  - `MyException.h`: Defines custom exceptions.

---

## Game Rules

1. The player creates a hero by selecting:
   - **Attributes**: Intelligence, Strength, and Dexterity, distributed within a total point limit.
   - **Background**: Defines the character's backstory (e.g., Soldier, Criminal).
   - **Race**: The character’s species (e.g., Human, Elf, Goblin).
   - **Class**: The type of fighter (e.g., Archer, Fighter, Wizard).
   - **Abilities**: Two combat abilities, each with a difficulty class and a damage score.
   - **Interaction**: The player navigates through rooms, interacts with objects, and fights enemies, aiming to complete all objectives and defeat all enemies to win the game.

---

## How to Play

1. At the start, the player must create their hero by selecting:
   - Name
   - Attributes
   - Background
   - Race
   - Class
   - Combat abilities

2. Once character creation is complete, the game begins, placing the player in an initial room.

3. In each room, the player can choose to:
   - Read a book (to gain intelligence).
   - Look at a statue (to gain dexterity).
   - Open a door or portal to enter another room.
   - Fight enemies in the room.

4. Each action may require a difficulty check based on a dice roll. If the dice roll is high enough, the action will succeed.

---

## Features and Object-Oriented Design

This project uses Object-Oriented Programming (OOP) principles and design patterns to create a structured and maintainable game architecture.

### Key OOP Concepts

- **Encapsulation**: Protects character attributes and abilities, ensuring data is managed securely (e.g., character stats are only accessible through specific methods).
- **Inheritance**: Provides a class hierarchy for characters, races, and abilities, allowing for shared functionality across similar entities (e.g., interface `IClasa` for character classes).
- **Polymorphism**: Enables flexible behavior depending on character class or race (e.g., unique abilities for each character class).
- **Composition**: Combines objects like rooms, characters, and objects, allowing for modular and flexible room configuration.
- **Abstraction**: Simplifies complex processes such as character creation and combat through high-level interfaces.

### Design Patterns Used

- **Builder Pattern**: Used for constructing complex objects like characters and enemies (e.g., `CharacterBuilder`, `EnemyBuilder`).
- **Factory Pattern**: Manages the creation of races and classes (e.g., `MainCharacterBuilder` for specific character types).
- **Singleton Pattern**: DungeonMaster centralizes control over game flow, avoiding multiple instances and ensuring data consistency.

These OOP concepts and design patterns contribute to a modular game design, making it easier to add new features and modify existing ones without impacting the core game structure.

