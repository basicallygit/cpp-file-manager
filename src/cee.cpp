#include "cee.hpp" //setup for windows / unix-like
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <chrono>
using namespace std;
int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "invalid argc" << endl;
    }
    else if (!strcmp(argv[1], "new")) {
        //check if user wants new project to be placed in a new directory (2nd argument)
        if (argc >= 3) {
            cout << "[CMD] mkdir " << argv[2] << endl;
            string dir = argv[2];
            system(("mkdir "+dir).c_str());
            CD((dir).c_str());
        }
        //create ./src, ./src/main.cpp, ./out
        cout << "[CMD] mkdir src\n";
        system("mkdir src");
        cout << "[CMD] mkdir out\n";
        system("mkdir out");
        cout << "[CMD] touch src/main.cpp" << endl;
        ofstream outfile("src/main.cpp");
        outfile << "#include <iostream>\nusing namespace std;\nint main() {\n    cout << \"Hello, World!\" << endl;\n    return 0;\n}" << endl;
        outfile.close();
    }
    else if (!strcmp(argv[1], "build")) {
        string outfile = WIND ? "out/main.exe" : "out/main";
        cout << "[CMD] gcc src/main.cpp -o " << outfile << " -lstdc++\n";
        //keep track of compilation time
        auto start = chrono::high_resolution_clock::now();
        //compile using gcc with stdc++ linker and place executable in ./out, can be changed
        system(("gcc src/main.cpp -o " + outfile + " -lstdc++").c_str());
        auto stop = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> time = stop - start;
        cout << "[OUTPUT] Finished in "<< time.count() << "ms" << endl;
    }
    else if (!strcmp(argv[1], "run")) {
        string outfile = WIND ? "out/main.exe" : "out/main";
        string runfile = WIND ? "if 1==1 \"out/main.exe\"" : "./out/main";
        //compile in the same way as build
        cout << "[CMD] gcc src/main.cpp -o " << outfile << " -lstdc++\n";
        auto start = chrono::high_resolution_clock::now();
        system(("gcc src/main.cpp -o " + outfile + " -lstdc++").c_str());
        auto stop = chrono::high_resolution_clock::now();
        chrono::duration<double, std::milli> time = stop - start;
        cout << "[OUTPUT] Finished in " << time.count() << "ms" << endl;
        //run ./out/main.*
        string args = "";
        if (argc > 2) {
            for (int i = 2; i < argc; i++) {
                args = args + " ";
                args = args + argv[i];
            }
        }
        cout << "[CMD] " << runfile << args <<  endl;
        if (args.length() != 0) {
            system((runfile+args).c_str());
        }else{
            system((runfile).c_str());
        }
    }
    else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help") || !strcmp(argv[1], "help")) {
        //list help
        cout << "\nC++ file manager with similar usage to rust's cargo (https://doc.rust-lang.org/cargo/)\n\nUsage: " << argv[0] << " [Option] [Optional args]\n\n"
        << "Options:\n\tnew [Optional dirname]: create a new project in cwd or specified new directory\n"
        << "\tbuild: Compile project in cwd but do not run\n"
        << "\trun [Optional cmdline arguments for the application]: Compile and run project in cwd, parse optional cmdline args\n"
        << "\t-h/--help/help: Shows this page" << endl;
    }
    else {
        cout << "Unknow argument: " << argv[1] << endl;
    }
    return 0;
}