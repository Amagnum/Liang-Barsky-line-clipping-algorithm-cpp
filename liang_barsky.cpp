# include <bits/stdc++.h>
using namespace std;

int main() {
    float X_MIN, X_MAX, Y_MIN, Y_MAX;
    float X1, Y1;
    float X2, Y2;

    // Assign Window Variables here w.r.t the given line has to be clipped
    cin >> X_MIN;// = 0;
    cin >> X_MAX;// = 8;
    cin >> Y_MIN;// = 0;
    cin >> Y_MAX;// = 4;

    // Assign point P1
    cin >> X1;// = -1;
    cin >> Y1;// = 1;

    //Assign point P2
    cin >> X2;// = 9;
    cin >> Y2;// = 3;

    vector<float> p(5,0);
    vector<float> q(5,0);
    vector<float> t(5,0);
    vector<string> enm(5);
    enm[1] = "Left"; enm[2] = "Right"; enm[3] = "Bottom"; enm[4] = "Top";

    p[1] = -1*(X2-X1); q[1] = X1 -X_MIN;
    p[2] = X2-X1; q[2]= X_MAX - X1;
    p[3] = -1*(Y2-Y1); q[3]= Y1-Y_MIN;
    p[4] = Y2-Y1; q[4]= Y_MAX-Y1;

    cout<<"p1 = -\u0394x = "<<p[1]<<"      "<<"q1 = x1 - x_min = "<<q[1]<<endl;
    cout<<"p2 = \u0394x  = "<<p[2]<<"      "<<"q2 = x_max - x1 = "<<q[2]<<endl;
    cout<<"p3 = -\u0394y = "<<p[3]<<"      "<<"q3 = y1 - y_min = "<<q[3]<<endl;
    cout<<"p4 = \u0394y  = "<<p[4]<<"      "<<"q4 = y_max - y1 = "<<q[4]<<endl;

    cout<<endl;

    // Initial Check to exclude line if pi == 0 && qi<= 0
    for(int i=1; i<=4; i++){
        if(p[i]==0 && q[i]<= 0){
            cout<<"Line Out Of Visible Region."<<endl;
            return 0;
        }
    }
   
   // Line parallel to left & right & in visible region
   if(p[1]==0 && p[2]==0){
       cout<<"Line is in visible region and is || to left and right edge of the window"<<endl;
       float xp1, yp1, xp2, yp2;
       xp1 = X1;
       xp2 = X1;
       yp1 = max(Y1, Y_MIN); yp2 = min(Y2, Y_MAX);
       float t_min = (yp1 - Y1)/(Y2-Y1);
       float t_max = (yp2 - Y1)/(Y2-Y1);
       cout<<"t_min = "<<(yp1 - Y1)<<"/"<<(Y2-Y1)<<" = "<<t_min<<endl;
       cout<<"t_max = "<<(yp2 - Y1)<<"/"<<(Y2-Y1)<<" = "<<t_max<<endl;
       cout<<"point corresponding to t_min :"<<endl;
       cout<<"\tx = "<<xp1<<" y = "<<yp1<<endl;
       cout<<"point corresponding to t_max :"<<endl;
       cout<<"\tx = "<<xp2<<" y = "<<yp2<<endl;
       return 0;
   }
   
   // Line parallel to top & bottom & in visible region
   if(p[3]==0 && p[4]==0){
       cout<<"Line is in visible region and is || to top and bottom edge of the window"<<endl;
       float xp1, yp1, xp2, yp2;
       yp1 = Y1;
       yp2 = Y1;
       xp1 = max(X1, X_MIN); xp2 = min(X2, X_MAX);
       float t_min = (xp1 - X1)/(X2-X1);
       float t_max = (xp2 - X1)/(X2-X1);
       cout<<"t_min = "<<(xp1 - X1)<<"/"<<(X2-X1)<<" = "<<t_min<<endl;
       cout<<"t_max = "<<(xp2 - X1)<<"/"<<(X2-X1)<<" = "<<t_max<<endl;
       cout<<"point corresponding to t_min :"<<endl;
       cout<<"\tx = "<<xp1<<" y = "<<yp1<<endl;
       cout<<"point corresponding to t_max :"<<endl;
       cout<<"\tx = "<<xp2<<" y = "<<yp2<<endl;
       return 0;
   }

   float t_min = 0;
   float t_max = 1;

   for(int i=1; i<=4; i++){
       cout<<"for "<<enm[i]<<" : "<<endl;
       if(p[i]<0){
           cout<<"\tPotential Entering"<<endl;
           t[i] = q[i]/p[i];
           cout<<"\tt = "<<q[i]<<"/"<<p[i]<<" = "<<t[i]<<endl;
           t_min = max(t_min, t[i]);
       }else if(p[i]>0){
           cout<<"\tPotential Leaving"<<endl;
           t[i] = q[i]/p[i];
           cout<<"\tt = "<<q[i]<<"/"<<p[i]<<" = "<<t[i]<<endl;
           t_max = min(t_max, t[i]);
       }
   }
   cout<<endl;

   cout<<"t_min = max(0, all_t_PE) = "<<t_min<<endl;
   cout<<"t_max = min(1, all_t_PL) = "<<t_max<<endl;

   cout<<endl;

   if(t_min > t_max){
       cout<<"Line outside visible region since t_min > t_max"<<endl;
       return 0;
   }

   float xp_1, yp_1, xp_2, yp_2;
   xp_1 = X1 + (X2 - X1)*t_min;
   yp_1 = Y1 + (Y2 - Y1)*t_min;

   xp_2 = X1 + (X2 - X1)*t_max;
   yp_2 = Y1 + (Y2 - Y1)*t_max;

   cout<<"point corresponding to t_min :"<<endl;
   cout<<"\tx = "<<xp_1<<" y = "<<yp_1<<endl;
   cout<<"point corresponding to t_max :"<<endl;
   cout<<"\tx = "<<xp_2<<" y = "<<yp_2<<endl;
}