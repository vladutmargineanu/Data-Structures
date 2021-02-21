#!/bin/bash

LabSD=1

echo ""
echo "=============== BUILDING LAB $LabSD ==============="
echo ""

make build

make run &> /dev/null

echo ""
echo "=============================================="

echo ""
echo "=============== CHECKING LAB $LabSD ==============="
echo ""

task="task"
bonus="bonus"

points1=(2.0 4.0 4.0 4.0)
points2=(1.0 2.0 3.0 1.0 3.0 5.0)
points3=(1.0 1.0)
points4=(1.0 2.5)
points5=(2.0 3.0 4.0)
points6=(1.0 1.0 1.0)
points7=(1.0 2.0 3.0 4.0 5.0)
points8=(1.0 1.0 1.0 1.0)
points9=(3.0 3.0 3.0 1.0)
points10=(1.0 2.0 3.0 4.0)
points11=(5.0 3.0 2.0)

ref_path=Ref/Lab$LabSD
out_path=Out/Lab$LabSD

ref_ext=".ref"
out_ext=".out"

it=0
grade="0.0"
max_grade="0.0"
labPoints="points$LabSD"

for ref_file in $((ls $ref_path/$task* && ls $ref_path/$bonus*) 2> /dev/null | xargs -n1 basename); do
    test=$(echo $ref_file | cut -d'.' -f1)
    out_file="$test$out_ext"
    current_task_score=points$LabSD[$it]
    max_grade=$(bc <<< $(echo "$max_grade + ${!current_task_score}"))

    ls $out_path/$out_file &> /dev/null
    if [ $? -gt 0 ]; then
        echo "Could not find $out_file .................... FAILED 0.0/${!current_task_score}"
    else
        if [ "$(diff -bB $ref_path/$ref_file $out_path/$out_file)" != "" ]; then
            echo "$test .................... FAILED 0.0/${!current_task_score}"
        else
            grade=$(bc <<< $(echo "$grade + ${!current_task_score}"))
            echo "$test .................... PASSED ${!current_task_score}/${!current_task_score}"
        fi
    fi

    it=$((it+1))

done

echo ""
echo "---------------------------------------------"
echo "Final grade: $grade/$max_grade"

make clean > /dev/null
rm -f $out_path/*

echo ""
