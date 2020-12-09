 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
## rhealth
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: \<[Andrea Zaragoza](https://github.com/AndreaZaragoza)\> \<[Sydney Garcia](https://github.com/supersydney22)\> \<[Kent Phan](https://github.com/Moltenfuzzy)\>
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
 >   * This project is important because its purpose is to help people become healthy. By calculating the Body Mass Index (BMI) of the user, the program can tailor a meal plan and exercise routine for them. Instead of having a doctor simply say to a patient “eat healthier and exercise more”, now the patient can see exactly what foods to include in their diet and how much exercise to do in order to take care of their health.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * C++ - a cross-platform language that can be used to create high-performance applications.
 >   * REST, RESTful - API libraries that work with C++ and are considering since we would like our project to use an application programming interface (API) 
 > * What will be the input/output of your project?
 >   * Our application focuses on the health and wellness of the user. It begins by asking the user for general information such as age, sex, weight, and height. These numbers are then used by the application to calculate Body Mass Index (BMI), which is a measurement of body fat based on height and weight. The user's BMI level is used to provide them with a meal plan and exercise routine tailored to this information. The purpose of the meal plan portion of the project is to provide the user with a list of foods and/or recipes they can consider adding to their diet in order to help balance or maintain their weight/BMI levels. The exercise portion of the project provides the user with exercise routines that help them balance or maintain their weight/BMI levels. Finally, the weight tracking feature of our application allows the user to maintian a record of their changes and progress in weight/BMI levels. As the user's weight/BMI levels change so do the recommended meal plans and exercise routines.
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
 >   * **Composite**: Like mentioned in class a composite design pattern allows for simple and complex hierarchies. In class Professor Reem used the example of graphics being broken down to lines, rectangles, and text. We thought this design pattern would work well for our project, because of the diversity our application will allow. Our application will not be restricted to any one group of people, but everyone. So this design pattern will allow us to put our users into specific hierarchies. Composite Pattern will aid us in declaring the Health Plan (component) and from it implementing the features Exercise Plan (leaf), Meal Plan (Leaf), and Weight Tracker/Plan (composite). 
 >   * **Facade**: The Facade design pattern hides the complexities of the system and provides an interface, in this case a graphical interface, for the client. We decided on this design pattern because the client should not have to worry about the complexities of the application. This lets the client focus on the purpose of the application itself. Therefore to implement a facade pattern, we must provide a simple interface, which is then linked to the GUI components in our application. The Facade Pattern will be helpful for implementing the Health App (compiler) feature of our project since it will allow us to define which of our subsystem objects should be called according to the request made. With Facade we can assign client requests to specific subsystem objects. That is Health Plan will determine, depending on the client request made, when to call Exercise Plan (subsystem), Meal Plan (susbsytem), or Weight Tracker/Plan (subsystem).
 >   * **Strategy**: The strategy pattern will be used within our exercise and meal plan subclasses. Since both of these subclasses will need to access an API to retrieve data, the strategy pattern allows us to efficiently reuse the code needed to handle anything related to an API. An API handler interface (context) is the base class that will have different HTTP methods implemented as subclasses such as, Call(GET), PUT, etc. This makes it so that there is one accessible interface that can be used by the subclasses (concrete strategies) of HealthPlan (strategy).  The reason as to why we decided to use this instead of the visitor pattern is due to the complexity as well as no known use for it within the project.  

 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 
![Design Diagram](https://user-images.githubusercontent.com/46156230/100715645-588c3400-336c-11eb-9ac6-2c0e1ed37ac1.png)
 
> The diagram above depicts all of the design patterns we plan to use in our final project, which are Composite, Facade, and Strategy. The general part of the diagram with the Health Plan (component) class and its three children Exercise Plan (leaf), Meal Plan (leaf), and Weight Tracker/Plan (composite) depict the Composite Pattern, which is where the main part of our computation will be. Our Facade and Strategy design patterns are both implemented through our Object Structure / Facade. This element is basically our main which will take in all of our user inputs, implementing our Facade Pattern, and also being translated to our GUI application, acting as our Strategy Pattern as well.

> The Facade Pattern is implemented by the Health App (compiler) and all the subsystems of Health Plan since Health App determines which subsystem object to assign the client request made. The Strategy Pattern allows us declare a common API algorithm CallAPI (context interface) in the API Handler interface (context) which configures Exercise Plan (concrete strategy) and Meal Plan (concrete strategy), and references Health Plan (strategy). API Handler uses Health Plan to call the algorithm defined by the two different concrete strategies. The two concrete strategies implement the algorithm using the Health Plan interface. The client is the user translating their answers into the main. The “client” is not any implementation on our part, it is just a representation of the user and where they will access our program.
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
## How to build
> We are using vcpkg to install libraries for C++

> Installation differs for each OS

> The dependencies include:

* gtest
* curl
* curlpp
* nlohmann_json

## Refer to [vcpkg](https://github.com/Microsoft/vcpkg/) for more information

## Requires
* Windows 7 or newer
* Git
* Visual Studio 2015 Update 3 or greater with the English language pack

### Install via vcpkg (WINDOWS64)

```.\lib\vcpkg\bootstrap-vcpkg.bat```

```.\lib\vcpkg\vcpkg integrate install```

```.\lib\vcpkg\vcpkg install gtest --triplet=x64-windows```

```.\lib\vcpkg\vcpkg install curl --triplet=x64-windows```

```.\lib\vcpkg\vcpkg install curlpp --triplet=x64-windows```

> nlohmann_json does not need to be installed as it is a submodule
