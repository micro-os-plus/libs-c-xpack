[![license](https://img.shields.io/github/license/micro-os-plus/libs-c-xpack)](https://github.com/micro-os-plus/libs-c-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/libs-c-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/libs-c-xpack/actions?query=workflow%3A%22CI+on+Push%22)
[![GitHub issues](https://img.shields.io/github/issues/micro-os-plus/libs-c-xpack.svg)](https://github.com/micro-os-plus/libs-c-xpack/issues/)
[![GitHub pulls](https://img.shields.io/github/issues-pr/micro-os-plus/libs-c-xpack.svg)](https://github.com/micro-os-plus/libs-c-xpack/pulls)

# Maintainer info

## Project repository

The project is hosted on GitHub:

- <https://github.com/micro-os-plus/libs-c-xpack.git>

To clone the stable branch (`xpack`), run the following commands in a
terminal (on Windows use the _Git Bash_ console):

```sh
rm -rf ~/Work/libs-c-xpack.git && \
mkdir -p ~/Work && \
git clone \
  https://github.com/micro-os-plus/libs-c-xpack.git \
  ~/Work/libs-c-xpack.git
```

For development purposes, clone the `xpack-develop` branch:

```sh
rm -rf ~/Work/libs-c-xpack.git && \
mkdir -p ~/Work && \
git clone \
  --branch xpack-develop \
  https://github.com/micro-os-plus/libs-c-xpack.git \
  ~/Work/libs-c-xpack.git
```

## Prerequisites

A recent [xpm](https://xpack.github.io/xpm/), which is a portable
[Node.js](https://nodejs.org/) command line application.

## Code formatting

Code formatting is done using `clang-format --style=file`, either manually
from a script, or automatically from Visual Studio Code, or the Eclipse
CppStyle plug-in.

## Prepare a new blog post

In the `micro-os-plus/web-jekyll` GitHub repo:

- select the `develop` branch
- add a new file to `_posts/libs-c/releases`
- name the file like `2020-12-19-libs-c-v1-1-0-released.md`
- name the post like: **µOS++ libs-c v3.0.1 released**
- update the `date:` field with the current date
- update the GitHub Actions URLs using the actual test pages

If any, refer to closed
[issues](https://github.com/micro-os-plus/libs-c-xpack/issues/)
as:

- **[Issue:\[#1\]\(...\)]**.

## Publish on the npmjs.com server

- select the `xpack-develop` branch
- commit all changes
- update versions in `README.md` and `README-MAINTAINER.md`
- update `CHANGELOG.md`
- commit with a message like _prepare v3.0.1_
- `npm pack` and check the content of the archive, which should list
  only `package.json`, `README.md`, `LICENSE`, `CHANGELOG.md`,
  the sources and CMake/meson files;
  possibly adjust `.npmignore`
- `npm version patch`, `npm version minor`, `npm version major`
- push the `xpack-develop` branch to GitHub
- the `postversion` npm script should also update tags via `git push origin --tags`
- wait for the CI job to complete
  (<https://github.com/micro-os-plus/libs-c-xpack/actions/workflows/CI.yml>)
- `npm publish --tag next` (use `npm publish --access public` when
  publishing for the first time)

The version is visible at:

- <https://www.npmjs.com/package/@micro-os-plus/libs-c?activeTab=versions>

## Testing

The project includes unit tests.

To run them, run:

```sh
cd libs-c-xpack.git
xpm run install-all
xpm run test
```

## Continuous Integration

The CI tests are performed on GitHub Actions, as the
[CI on Push](https://github.com/micro-os-plus/libs-c-xpack/actions?query=workflow%3A%22CI+on+Push%22)
workflow.

## Update the repo

When the package is considered stable:

- with Sourcetree
- merge `xpack-develop` into `xpack`
- push to GitHub
- select `xpack-develop`

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @micro-os-plus/libs-c`
- `npm dist-tag add @micro-os-plus/libs-c@3.0.1 latest`
- `npm dist-tag ls @micro-os-plus/libs-c`

## Share on Twitter

- in a separate browser windows, open [TweetDeck](https://tweetdeck.twitter.com/)
- using the `@micro_os_plus` account
- paste the release name like **µOS++ libs-c v3.0.1 released**
- paste the link to the Web page release
- click the **Tweet** button
