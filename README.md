# File manager similar to rust's cargo but for C++
### Cargo: [Rust Cargo](https://doc.rust-lang.org/cargo/)
### Features:
- new (initialize new project)
- build (compile project in cwd without running)
- run (build and run, passing cmdline arguments is allowed)
- help/-h/--help (brings up a page similar to this)
### Requirements
- C++ 11 or greater
- gcc (or a similar C++ compiler, will need manual editing for other compilers)
### Installation on Linux / WSL:
## One liner:
```bash
git clone https://github.com/basicallygit/cpp-file-manager.git cppfm_src && cd cppfm_src && chmod +x setup.sh && sudo ./setup.sh
```
## Manual:
```bash
~ install gcc with your system\'s package manager
~ git clone https://github.com/basicallygit/cpp-file-manager.git cppfm_src
~ cd cppfm_src
~ sudo gcc src/cee.cpp -o /usr/bin/cee
```
### Installation on Windows:
## One Liner for powershell:
## Manual:
```powershell
~ git clone https://github.com/basicallygit/cpp-file-manager.git cppfm_src
~ cd cppfm_src
~ gcc src/cee.cpp -o cee.exe -lstdc++
# Add cee.exe to your PATH environment variable
```
### Open to suggestions for new features!
