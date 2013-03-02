/*Version 1.0, Feb 2010

Copyright (C) 2010 Free Software Foundation, Inc.  
51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA

Everyone is permitted to copy and distribute verbatim copies
of this license document, but changing it is not allowed.

Copyright 2010 Kshitiz Agarwal 
the program is distributed under the terms of the GNU General Public License
This file is part of UFS.

UFS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

UFS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with UFS. If not, see <http://www.gnu.org/licenses/>. For any bug, kindly mail that to k.agarwal4@gmail.com*/

#include <unistd.h>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>
int main()
{
    int i;
    FILE *f1;
    system("sudo gcc ufs.c");
    printf("UFS version 1.0, Copyright (C) 2010 Kshitiz Agarwal. UFS comes with ABSOLUTELY NO WARRANTY; for details type `show w'.  This is free software, and you are welcome to redistribute it under certain conditions; type `show c' for details\n\n");
    printf("\n\nEnter your preference - sequence is in descending order\n\n");
    printf(" 0 - Default computing\n");
    printf(" 1 - Connectivity-length-size\n");
    printf(" 2 - Connectivity-size-length\n");
    printf(" 3 - Length-connectivity-size\n");
    printf(" 4 - Length-size-connectivity\n");
    printf(" 5 - Size-length-connectivity\n");
    printf(" 6 - Size-connectivity-length\n\n");
    scanf("%d", &i);
    f1 = fopen("input1.txt","w");
    fprintf(f1, "%d", i);
    fclose(f1);
    if(i!=0)
    {
    printf("\n\n Enter suitable option\n\n"); 
    printf(" 1 - Internet + small + light tasks\n");
    printf(" 2 - Normal + small + light tasks\n");// 1
    printf(" 3 - Internet + small + heavy tasks\n");// 1      
    printf(" 4 - Normal + small + heavy tasks\n");
    printf(" 5 - Internet + large + light tasks\n");
    printf(" 6 - Normal + large + light tasks\n");// 1
    printf(" 7 - Internet + large + heavy tasks\n");// 1      
    printf(" 8 - Normal + large + heavy tasks\n\n");
    scanf("%d", &i);
    f1 = fopen("input2.txt","w");
    fprintf(f1, "%d", i);
    fclose(f1);
    while(1)
    {
    system("sudo ./a.out");
    sleep(15);
    }
    }
    else system("sudo ./a.out");
    return(1);
}
