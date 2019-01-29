# IFT-3100-E05
---------------------
Projet en infographie
----------------------

Description
----------------------

Ajouter une description....

-------------------------

# Procédures de travail
----------------------

1-Create a feature in git 

2-Check if the issue is already in progress in the relevant project's board

3-Move the issue to the in progress column in the board

4-Update your local master: git checkout master & git pull origin master

5-Create the corresponding branch following the convention #issue-descriptive-name, e.g. 21-adding-branching-documentation. The branch name should be lower case since it's sometimes used as http route, which are case insensitive.

6-Make some tests, some code, etc.

7-Add your changes to your local git index: git add .

8-Commit your changes to your local git repository: git commit -m "Some descriptive message"

9-Synchronise your code with master in case somebody else merged in it in the mean time: git checkout master & git pull origin master & git checkout your-branch & git merge master

10-Check locally if your branch is compiling and works properly

11-Push your branch to the repository: git push origin your-branchs

12-Go to the github repository , and create a pull request from your branch in master. Call it your-branch in master.

13-Add in the description resolves #issue, this will link the pull request to the issue, and automatically manage it.

14-Add the right label in the pull request: feature / bugfix / etc.

15-Add any reviewers you think is the most appropriate (at least 2)

16-Confirm the pull request creation

17-When all checks passed, two people approved the pull request and it's ready to merge, merge it yourself.

18-When the PR successfully merged, delete the branch on the pull request page.

