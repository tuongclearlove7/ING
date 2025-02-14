
# [**ING::ApplicationManager**](./..//ING/ApplicationManager.md) #
                
## **Basic Info** ##
- `Description` **:** Manages applications
- `Parent` **:** ING::Utils::Singleton < [**ING::ApplicationManager**](./..//ING/ApplicationManager.md) > , ING::Utils::Square
- `Project` **:** **ING**
                    
## **Members** ##
                            
- `Constructor` **:**
                    
    + **ApplicationManager**() 
                        
                            
- `Destructor` **:**
                
    + **~ApplicationManager**() 
                    
                
- `Property` **:**
    
                
    + std::unordered_map < std::string,[**ING::IApplication**](./..//ING/IApplication.md)* >  **name2ApplicationMap**  **:** name to application map
        
                    
        + `Item Getter` :
                                            
                                
            + IApplication* **GetApplication**(const std::string & name)  **:** get application by name
                                    
                                
- `Method` **:**
    
                
    + virtual bool **Init**()  **:** overrided from ING::Utils::Square::**Init**()
                        
                    
    + virtual bool **Run**()  **:** overrided from ING::Utils::Square::**Run**()
                        
                    
    + virtual bool **Release**()  **:** overrided from ING::Utils::Square::**Release**()
                        
                    
    + void **Start**()  **:** called when the engine start running, it will call **Start** method of each application
                        
                    
    + void **PreUpdate**()  **:** called before **Update**, it will call **PreUpdate** method of each application
                        
                    
    + void **Update**()  **:** called every frame, it will call **Update** method of each application
                        
                    
    + void **LateUpdate**()  **:** called after **Update**, it will call **LateUpdate** method of each application
                        
                    
    + void **PreRender**()  **:** called before **Render**, it will call **PreRender** method of each application
                        
                    
    + void **Render**()  **:** called when the engine rendering, it will call **Render** method of each application
                        
                    
    + void **LateRender**()  **:** called after **Render**, it will call **LateRender** method of each application
                        
                    
    + void **AddApplication**([**ING::IApplication**](./..//ING/IApplication.md)* application)  **:** add an application for managing
                        
                    
    + void **RemoveApplication**([**ING::IApplication**](./..//ING/IApplication.md)* application)  **:** remove an application that is currently managed
                        
                    