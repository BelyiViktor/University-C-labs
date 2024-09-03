#include"iowrapper.h"
#include"consts.h"
#include<stdint.h>
#include"struct_student.h"

void convert_binary_file_to_text(FILE *textfile, FILE *binfile)
{
    rewind(textfile);
    rewind(binfile);
    while (!feof(binfile))
    {
        struct student curent_strudent = { "None", "None", { 0, 0, 0, 0 } };
        fread(&curent_strudent, sizeof(struct student), 1, binfile);
        if (!feof(binfile))
        {
            fprintf(textfile, "%s\n", curent_strudent.surname);
            fprintf(textfile, "%s\n", curent_strudent.name);
            fprintf(textfile, "%d\n", curent_strudent.subject_grades[0]);
            fprintf(textfile, "%d\n", curent_strudent.subject_grades[1]);
            fprintf(textfile, "%d\n", curent_strudent.subject_grades[2]);
            fprintf(textfile, "%d\n", curent_strudent.subject_grades[3]);
        }
    }
}
