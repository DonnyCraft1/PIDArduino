# Introduction

First off, thank you for considering contributing to PIDArduino

PIDArduino is an open source project and we love to recieve cotributions from our community - you! There are many ways to contribute, from writing tutorials, improving the documentation, submitting bug reports and feature request or writing code for the actual library.

# Rules

* **§1:** Before submitting an issue, research to ensure it hasn't been submitted before. Avoid duplicate issues

* **§2:** Use common sense

# Getting started

*Please do not edit the master branch, always use the [develop](https://github.com/DonnyCraft1/PIDArduino/tree/develop) branch or a new feature branch when contributing! The only exception is critical hotfixes.*

*Please read up on the [gitflow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow) workflow before forking the repo if you plan on making a pull request. We try to keep the master branch clean, and merge develop into master only on new releases. The only exception is documentation. It is merged into master and develop regardless the state of releases. You can think of it as a non-critical hotfix.*

---

For something that is bigger than a one or two line fix:

1. First go to the [issue tracker](https://github.com/DonnyCraft1/PIDArduino/issues) and open a new issue and share your toughts about what you would like to change, either a bug you found or a feature you would like to implement
2. Create your own fork of the repo
3. Create a new branch from the develop branch called `feature/new-feature`, all lower-case and replacing `new-feature` with a descriptive name for the feature. If it's a hotfix, create a new branch from the master branch and call it `hotfix/new-hotfix`, all lower-case and replacing `new-hotfix` with a descriptive name for the hotfix
4. Do the changes in *your* fork
5. If you like the fork and think the project could use it, consider a pull request
6. Create a pull request with the [develop](https://github.com/DonnyCraft1/PIDArduino/tree/develop) branch as the *base* branch

---

Small contributions such as fixing spelling errors, can be submitted by a contributor as a patch directly on the [develop](https://github.com/DonnyCraft1/PIDArduino/tree/develop) branch.

This includes:

* Spelling / grammar fixes
* Typo correction, white space and formatting changes
* Comment clean up

---

Critical bugs can be merged direclty into the master branch as a *hotfix*.
But remember to also merge it to the develop branch before deleting the *hotfix* branch.

# Commit message conventions

* The summary should be [capitalized](https://en.wikipedia.org/wiki/Capitalization) (first letter uppercase)
* The summary should *not* end with a period
* The summary should be short and descriptive
* The description should explain all the changes you've made
