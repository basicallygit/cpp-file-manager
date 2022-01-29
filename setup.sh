#!/bin/bash
if [[ $EUID -ne 0 ]]; then
    echo "Please run again as root to install"
    exit 1
fi
function install_gcc {
    YUM=$(which yum)
    APTGET=$(which apt-get)
    PACMAN=$(which pacman)
    APT=$(which apt)
    if [[ ! -z $YUM ]]; then
        yum install gcc
    elif [[ ! -z $APTGET ]]; then
        apt-get install gcc
    elif [[ ! -z $APT ]]; then
        apt install gcc
    elif [[ ! -z $PACMAN ]]; then
        pacman -S gcc
    else
        echo "unable to identify your package manager"
        exit 1;
    fi
}
if [ -e /usr/bin/gcc ]; then
    echo "/usr/bin/gcc satisfied"
else
    read -p "gcc not found / installed, install? [Y/n]: " -n 1 -r
    case $REPLY in
        [yY])
            install_gcc
            break
            ;;
        [nN])
            echo "manaully cancelled gcc install, exiting.."
            exit 1;
            break
            ;;
        *)
            install_gcc
            ;;
    esac
fi
echo "Compiling.. "
#change cee.cpp and /bin/cee if you wish to change the filename
gcc ./src/cee.cpp -o /usr/bin/cee -lstdc++
echo "Compiled to /usr/bin/cee"
