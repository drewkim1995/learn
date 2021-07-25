// https://leetcode.com/problems/powx-n/

class Solution
{
    public:
        double myPow(double x, int n)
        {
            //cout << endl << x << "^" << n << endl;
            double res=1.0;
            for(int i=n;i;i/=2)
            {
                /*
                cout << "i = " << i << " | "
                     << "res = " << res << " | "
                     << "x = " << x << " || ";*/
                // If odd
                if(i&1)
                    res*=x;
                x*=x;
                /*
                cout << "res = " << res << " | "
                     << "x = " << x << endl;*/

            }
            return n>=0?res:1/res;
        }
};