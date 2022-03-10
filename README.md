
# Fanduel NBA Best Possible Lineup
 > 
 
  Authors: [Jordan Kuschner](https://github.com/marinersjk00),  [Chris Chua](https://github.com/cchua00) , [Andrew Ocegueda](https://github.com/xTh3Unkn0wnx), [Bilal Nasir](https://github.com/noshotbigjuicersbilal151)
 

 



## Project Description


On websites like FanDuel.com and DraftKings.com, one can play "daily fantasy sports" which differ from typical fantasy sports in that your team is only your team for one day. In regular fantasy basketball, when you draft your team at the start of the year, you're stuck with pretty much the same team throughout the year whether they're good, bad, healthy, or unhealthy. In daily fantasy basketball, if one of your players gets a season-ending injury, you will be down for a night but can just simply choose to avoid picking that player the next time you play.

The goal of daily fantasy is to draft the best possible lineup for that day's slate of games. The most surefire way to do this, although there is no surefire way since we cannot predict the future, would be to draft all the top players. However, this is not possible because there is an implemented salary cap. The star players who typically have great games every night are far more expensive than the secondary players who average much lower statistics. But, on any given night, any player can have a great game regardless of how consistently good they've been in the past. Thus, the goal of daily fantasy is to work within the limitations of the salary cap to find the best possible lineup for that day. This will almost always be a mix of a couple big stars and more secondary players that one might personally think will do well that night.

Now, again, we cannot accurately predict the future. That said, we can use past data to help us in our attempts to accurately predict the future. The goal of our program is to be able to return the best possible lineup from a given past day knowing all the stats of all the possible players now exist and are unchangeable. The user should be able to enter a day in the past that basketball games occurred, and from that the program should return at least the best possible lineup, if not the top 2 or 3 best possible lineups. The user can then use this information to try and find more under the radar players that seem to consistently do well when he/she is creating his future lineups. We plan to do as much as possible in C++, although SQL and possibly JDBC may be necessary to organize data.

  ## Phase II

## Class Diagram
 The overarching class is the Team class which will hold the total team salary, the total team points, and the date to retrieve a team from. Player will inherit from team, with each player having it's individual statistics and cost to the team salary. Each player has a specific position. The position doesn't matter much except that certain players can only fill out certain positions and there has to be 2 players of each position, except Center which only needs 1.
 
 ## Phase III

We are using a composite pattern for implementing out Team, Player, and position classes. This is because our inheritance is relatively simple. All of our subclasses are really just smaller instances of their parents. For example, Team is a collection of Players, and every position player is still a player on a team. We don't have many complicated strategies or decisions involved in this portion so we are ok with using a composite design pattern. For our comparison between players, however, we may need to use a strategy pattern instead. As we get into comparing players to see who goes on our best teams, we could run into a multitue of iffy situations such as comparing maximum points vs points per dollar, or considering a tie in points or if a more valueable position is filled. We will also need to consider additonal factors like if our team isfull at a certain position or if a more valueable player exists that we cannot afford. Overall, there are many complications that could occur as a result of comparing between players, so a strategy pattern would be best. The comparisons haven't been implemented yet, but following the composite design pattern has allowed us to stay focued on the specific tasks we are working on. It is easy to think of new ideas while writing the code, but following the design pattern has forced us to keep things simple for this portion and save the more advanced stuff for the strategy side.

 
 >
 ## Screenshots
 Screenshots of the input/output after running your application  
 ![image](https://user-images.githubusercontent.com/97256479/157591012-844958c9-448f-4b47-9565-21c456831cdf.png)  
 ![image](https://user-images.githubusercontent.com/97256479/157591040-80d04981-d332-4022-b2cc-bf026e1c6784.png)
 ## Installation/Usage 
 In order to install the program first make sure you are in the your home directory by using the following command:
   ```
   $ cd ~ 
   ```
   Then clone the repository by using the git clone command followed by the URL repository link:
   ```
   $ git clone https://github.com/cs100/final-project-jkusc002-bnasi004-cchua032-aoce003.git
   ```
   Change the directory from home to the repository with the following: 
   ``` 
   $ cd final-project0jkusc002-bnasi004-cchua032-aoce003/ 
   ```
   After cloning the repository, run the following command in order to install the extensions for the requests, pandas, and beautiful soup extensions for python 3 and higher use: 
   ```
   $ python3 -m pip3 install --user requests
   $ python3 -m pip3 install --user pandas
   $ python3 -m pip3 install --user bs4
   ```
   for python 2.7 and below use:
   ``` 
   $ python3 -m pip install --user requests
   $ python3 -m pip install --user pandas
   $ python3 -m pip install --user bs4
   ```
  After all of these have successfully been installed, the program will be able to run.   
  In order to run the program, first compile main.cpp with following command:   
  ```
   $ g++ -o FanduelProgram main.cpp 
   ```
    
  Then run the executable using the following command: 
   ``` 
   $ ./FanduelProgram
   ```
   The program will ask you for a month, day, and year in order.
  ```  
   Enter month: 02
   Enter day: 28 
   Enter year: 2015 
  ``` 
  **NOTE: Example Date is given above**
  
  Inputting the date will bring up the best line up possible on that day.  
  Inputting the date as 04/13/2016 or 4/13/2016 will find the same best line up.  
  
  **The program will only work if the user inputs numbers for the date.**   
  **Inputting "feb" for the month will not output the correct data.**  
  
  __Due to the website used in the webscrapper, the date of the earliest game that can find the best line up is October 28, 2014 (10,28,2014) and the date of the last game is     June 22, 2021 (06,22,2021).__
 
  ## Testing
  For testing we adopted the google test framework. We ran unit tests on all of our functions including our webscraper. We created the file CMakeLists.txt to generate an executable for the unit tests under a file called unit_test. This will pull the unit tests from unit_test.cpp. 
  We basically created two test suites, one that uses a fixed csv file that is generated at the beginning of the tests, and one that tests our webscraper. 
  
  ## Fixed CSV Test Suite
  In this test suite we test our algorithm that creates the best line up to ensure functionality. This consists of multiple functions including: 
  ```
   getPositions()
   valueSorter()
   bestByValue()
   sortByPointsScored()
   spendRemainingCapOnPoints()
   sortByPosition()
  ``` 
  This test suite is reliant on asking the tester to give the python webscraper a certain date. We know which values to expect for each function so we simply pass the test if the values match up. We ensure this works because if we enter a different date, all of our tests fail. 
  
  ## Webscraper Test Suite
  Testing the webscraper proved to be quite difficult. Our webscraper is implemented in python and its primary use is to give us a csv file to read. Since googletest framework is used for c++ we had to get creative on how to test it. Our solution was to test that it would indeed create the csv file needed. We simply remove the existing csv file, call our webscraper, and check if a new file is created. We also test if the date that was input is valid. We do this by checking the contets of the csv file, if it's empty itll fail and if its full it'll pass.

 
