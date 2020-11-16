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
 >   * This project is important because its purpose is to help people become healthy. By seeing where there are gaps in the health of the user, the program will tailor a meal plan and exercise routine for them. Instead of having a doctor simply say to a patient “eat healthier and exercise more”, now the patient can see exactly what foods to add to their diet and how much exercise to do in order to fill in the gaps in their health.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * [toolname](link) - Short description
 >   * C++ - a cross-platform language that can be used to create high-performance applications.
 >   * GTK, Qt, or wxWidgets - GUI libraries that work with C++ and that we could possibly use since we would like to have graphical user interface (GUI) within our project idea. We are not too familiar with creating GUIs, so we will be starting earlier to test and see which tools we prefer. 
 >   * REST, RESTful - API libraries that work with C++ and are considering since we would like our project to use an application programming interface (API) 
 > * What will be the input/output of your project?
 >   * Our application will focus on the health and wellness of the user by asking the user for general information such as age, sex, weight, and height, as well as more detailed information obtained through blood tests such as cholesterol levels, blood pressure, vitamin levels, and iron (hemoglobin) levels. These numbers will be used by the application to output a meal plan and exercise routine tailored to the information that the user inputed. We are not sure if we may just generate a list of foods the user can consider adding to their diet to help balance any deficiencies or if in addition to a list also provide the user with recipes to use these foods in (either pull recipes from the web or generate them ourselves). As for the exercise we could ask the user for what type or form of exercise they like and provide tailored routines based on that.
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
 >   * **Composite**: Like mentioned in class a composite design pattern allows for simple and complex hierarchies. In class Professor Reem used the example of graphics being broken down to lines, rectangles, and text. We thought this design pattern would work well for our project, because of diversity our application will allow. Our application will not be restricted to any one group of people, but everyone. So this design pattern will allow us to put our users into specific hierarchies. 
 >   * **Facade**: The Facade design pattern hides the complexities of the system and provides an interface in this case a graphical interface for the client. We decided on this design pattern because the client should not have to worry about the complexities of the application. This lets the client focus on the purpose of the application itself. Therefore to implement a facade pattern, we must provide a simple interface, which is then linked to the GUI components in our application. 
 >   * **Visitor**: We have not gone over the visitor design pattern yet in class, but from our group’s research this pattern seems to be useful for our project. Since our project will be taking many different inputs from the user and having to do different calculations for each input the visitor design pattern will make adding new systems easy, because we will not have to affect other existing item classes that we have created. The visitor design pattern is used when you perform an operation on similar kinds of objects. Since our inputs can be diverse we will use this pattern for each group we create and conduct their calculations within them
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
> The following diagram depicts all of the design patterns we plan to use in our final project, including Composite, Visitor, and Facade. The general part of the diagram with the WeightTracker class and its two children Exercise and MealPlan depict the composite pattern, which is where the main part of our computation will be. Our Facade and Visitor design pattern are both implemented through our Object Structure / Facade. This element is basically our main which will take in all of our user inputs, implementing our visitor pattern, and also being translated to our GUI application, acting as our facade pattern as well. The client is the user translating their answers into the main. The “client” is not any implementation on our part, it is just a representation of the user and where they will access our program.
 
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
 
