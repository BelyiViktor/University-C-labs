#include"iowrapper.h"
#include"consts.h"

int count_bigger_than_number(FILE *f, int return_code, double average)
{
    int answer = 0;
    if (return_code == OK)
    {
        double cur_member = 0;
        rewind(f);
        while (fscanf(f, "%lf", &cur_member) == 1)
        {
            if (cur_member > average)
                answer++;
        }
    }
    return answer;
}