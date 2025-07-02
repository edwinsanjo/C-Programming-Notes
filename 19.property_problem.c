#include <stdio.h>

int main() {
    // 1st -1/4 2nd remainig x1/4 +100 3rd remaining x1/4 +200 4th remaining all

    float total, remaining=0.0;
    for(float i=1.0;i<99999.0;i++){
        total = i;
        // child 1
        remaining = total - (total*0.25);
        //child 2
        remaining = remaining - ((remaining*0.25)+100.0);
        //child 3
        remaining = remaining - ((remaining*0.25)+200.0);
        // child 4
        remaining = remaining - (total*0.25);

        printf("%f . remaining: %f\n", i, remaining);

        if (remaining==0.0)
        {
            break;
        }
        

    }
    return 0;
}
