# Flowchart Designer — Partial C++ Implementation

A Windows C++ coursework codebase using CMUgraphics. The checked-in implementation includes a graphical shell, an application manager, statement/connector abstractions, and an action for adding value assignments.

## Current status

The available source is incomplete: `ApplicationManager::ExecuteAction` constructs `AddValueAssign`, while condition, selection, and exit branches remain TODOs; `GetStatement` returns `NULL`. The repository does not demonstrate a complete flowchart simulator, save/load engine, or execution engine. Toolbar images represent intended actions, not proof that those actions are implemented.

## Structure and design

All original code is under `PT_project-master/`. `ApplicationManager` owns statement and connector collections; `Actions/` represents user commands; `Statements/` contains statement types; `GUI/` separates input/output; `CMUgraphicsLib/` contains the graphics library and its existing documentation. [Class diagram](PT_project-master/ClassDiagram.jpg) is a supplied design asset, not a screenshot of a completed application.

## Build guidance

Open `PT_project-master/PT Project.sln` in Visual Studio with Desktop development with C++ and the Windows SDK. The CMUgraphics code relies on Windows-specific headers and original include conventions. Run with `PT_project-master/` as the working directory so relative image paths resolve. The review did not build this Windows GUI project in the Linux environment.

## Next steps

Complete hit testing and action dispatch, audit statement/connector ownership, implement validation and execution before claiming simulation, and add a verified Windows build configuration. No Linux build CI is supplied because it would not honestly validate this codebase.
