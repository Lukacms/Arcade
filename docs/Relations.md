# Arcade - Hierarchical relation between the classes
This Readme describe the relation between the classes and different parts of this project.

```mermaid
flowchart TB
    subgraph displays
    ID(IDisplay) --> D[Display]
    end
    subgraph core
    C(Core) --> M(Menu)
    end
    subgraph games
    IG(IGames) --> G(Game)
    end
    ID --> C
    C --> IG
```
