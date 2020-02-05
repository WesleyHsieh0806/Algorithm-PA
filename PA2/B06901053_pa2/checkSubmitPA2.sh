#!/bin/bash

#############################################################################
# File       [ checkSubmitPA2.sh ]
# Author     [ funnymean ]
# Modified   [ 2018/03/05 by An-Wei, Hsu]
# Synopsis   [ simple test for algorithm PA2 homework format program ]
# Date       [ Ver. 1.4 started 2017/03/18 ]
#############################################################################

check_dir=check_$$

if [ "$1" == "" ]; then
    echo "Usage:   ./checkSubmitPA2.sh <fileName>"
    echo "Example: ./checkSubmitPA2.sh b06901000_pa2.tgz"
    echo "This program will build a directory named \"$check_dir\""
    exit 1
fi

tgz_file=$1

echo "[Info] Checking tgz file \"$tgz_file\""
if [ ! -f $tgz_file ]; then
    echo "**ERROR** Cannot find .tgz file \"$tgz_file\"!"
    exit 2
fi
if [ -d check_$$ ]; then
    echo "**ERROR** Directory \"$check_dir\" exists!"
    echo "**ERROR** Please delete the directory and try again!"
    exit 1
fi

if [ ! "$tgz_file" == *_pa2.tgz ]; then
    echo "**ERROR** Wrong naming format \"$tgz_file\"!"
    echo "**ERROR** tgz file should be named as \"<stu_id>_pa2.tgz\" (e.g. b06901000_pa2.tgz)"
    exit 2
fi

mkdir $check_dir
cd $check_dir

tar zxvf ../$tgz_file

stuid=`basename $tgz_file | sed -e 's/_.*//'`
echo "[Info] Your submission file: $tgz_file"
echo "[Info] Your student ID: $stuid"
stu_dir=${stuid}_pa2

echo "[Info] Checking \"${stu_dir}/\" ..."
if [ ! -d ${stu_dir} ]; then
    echo "**ERROR** Cannot find directory \"${stu_dir}/\""
    cd ..
    rm -rf $check_dir
    exit 2
fi

src_dir=${stu_dir}/src
echo "[Info] Checking \"${src_dir}/\" ..."
if [ ! -d ${src_dir} ]; then
    echo "**ERROR** Cannot find directory \"${src_dir}/\""
    cd ../
    rm -rf $check_dir
    exit 2
fi

src_dir_result=($(ls -d ${src_dir}/*/ 2>/dev/null))
if [ ! $src_dir_result == "" ]; then
    echo "**ERROR** Detected \"$src_dir_result\" in \"${src_dir}/\""
    echo "**ERROR** No directories are allowed in \"${src_dir}/\""
    cd ../
    rm -rf $check_dir
    exit 2
fi

src_files=$(ls ${src_dir})
for file in ${src_files}; do
    case "$file" in
    *.h | *.hpp | *.c | *.cpp ) 
        ;;
    *)
        echo "**ERROR** Detected \"$file\" in \"${src_dir}/\""
        echo "**ERROR** Only *.h *.hpp *.c *.cpp are allowed in \"${src_dir}/\""
        cd ../
        rm -rf $check_dir
        exit 2
        ;;
    esac
done

makefile1=${stu_dir}/makefile
makefile2=${stu_dir}/Makefile
echo "[Info] Checking \"${makefile1}\" or \"${makefile2}\" ..."
if [ ! -f ${makefile1} ] && [ ! -f ${makefile2} ] ; then
    echo "**ERROR** Connot find \"${makefile1}\" or \"${makefile2}\""
    cd ../
    rm -rf $check_dir
    exit 2
fi

readme=${stu_dir}/readme.txt
echo "[Info] Checking \"${readme}\" ..."
if [ ! -f ${readme} ]; then
    echo "**ERROR** Cannot find \"${readme}\""
    cd ../
    rm -rf $check_dir
    exit 2
fi

bin=${stu_dir}/mps
echo "[Info] Checking \"${bin}\" ..."
if [ ! -f ${bin} ]; then
    echo "**ERROR** Cannot find \"${bin}\""
    cd ../
    rm -rf $check_dir
    exit 2
fi

echo "[Info] Recompiling ..."
rm $bin
cd ${stu_dir}
make clean
make
cd ..

echo "[Info] Checking \"${bin}\" after compilation ..."
if [ ! -f ${bin} ]; then
    echo "**ERROR** Cannot find \"${bin}\" after compilation."
    echo "**ERROR** Please check your makefile settings."
    cd ../
    rm -rf $check_dir
    exit 2
fi

echo "=============================================="
echo "Congratulations!  Passed submission checking! "
echo "=============================================="
cd ../
rm -rf $check_dir
