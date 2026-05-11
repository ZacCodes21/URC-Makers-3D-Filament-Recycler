### Note
If you are new to Git or Github I recommend using [Github Desktop](https://desktop.github.com/download/), which handles local commits and pushing to origin making it easier to open pull requests on the main Github. Contributing tips assume using this application.

I am also relatively new to Git, so if you run into issues trying to use terminal I will likely be just as confused. Github Desktop is certainly the easiest and least error-prone way of contributing. A lot of what I talk about in Contributing can be skipped by using the application.
# URC/Makers 3D Filament Recyler 2026
## Intro to Git
Please checkout Github's [Using Git](https://docs.github.com/en/get-started/using-git/about-git) article to learn about Git. It also contains useful information about the basic commands like `git pull origin main`, `git push origin main`, `git commit -m "Hello, world!"`, `git checkout`, etc..

You may need to do some setup with Git or Github before proceeding. If you have a Github account, you should be good to go.
## Contributing for the first time
WIP
1. [Fork](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo) this repository. There should be a button on this page to do so. This creates a copy of the main repository on your Github known as a fork.
2. Make a new "local" folder/directory in your Onedrive Documents or your Desktop (Onedrive recommended).
3. Clone your fork into your new folder. What this step does is download the files in the fork onto your computer. This folder is known as the "local repository". There are two ways to do this:
  - In Github Desktop, go `File > Clone Repository > URL` (third tab) and paste `https://github.com/[YOUR-USERNAME]/URC-Makers-3D-Filament-Recycler`. Set the local path to be your folder and press `clone'
  - In your folder, open Command Prompt and run `git clone https://github.com/[YOUR-USERNAME]/URC-Makers-3D-Filament-Recycler`.
4. When this is done, you can verify in Command Prompt that the local repo is linked to your fork (your "cloud" repo on Github) by running `git remote -v`. You should see the same URL that you entered:

`C:\Users\benja\OneDrive\Documents\3dfilamentrecycler>git remote -v`
`origin  https://github.com/ZacCodes21/URC-Makers-3D-Filament-Recycler.git (fetch)`
`origin  https://github.com/ZacCodes21/URC-Makers-3D-Filament-Recycler.git (push)`

  What this means is when you stage and commit changes from your local repository, they will be pulled into your fork in the cloud. From your fork, you can then open a pull request on Github to merge the changes into the main repo.
  
5. Add the main repo as another remote named "upstream". This lets Git know that your origin remote is a fork of the main repo:
`git remote add upstream https://github.com/ZacCodes21/URC-Makers-3D-Filament-Recycler.git`

  Again validate with `git remote -v`.

7. Sync your fork with upstream by running consecutivel (^you will have to run this each time you wish to contribute):

`git fetch upstream`
`git checkout main`
`git merge upstream/main`

7.[Sync](https://docs.github.com/en/get-started/using-git/getting-changes-from-a-remote-repository) your local repo with your fork^:

`git pull origin main`

9. Make your changes!
10. Stage your changes^:

`git add -a`

11. Commit your changes^:

`git commit -m "updated arduino sketches"`

10. [Push](https://docs.github.com/en/get-started/using-git/pushing-commits-to-a-remote-repository) your changes^:

`git push origin main` 

11. On Github, open a pull request from your forked repo^. It will then be reviewed and merged into the main repo.
