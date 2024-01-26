#ifdef __cplusplus2
extern "C"
{
#endif

#include <iostream>
#include "headers/operations.h"
    using namespace std;

    template <size_t N>
    bool contains(int (&a)[N], int &x);
    template <size_t N>
    int *setUnion(int (&a)[N], int (&b)[N]);
    template <size_t N>
    int *setIntersection(int (&a)[N], int (&b)[N]);
    template <size_t N>
    int *setComplement(int (&a)[N], int (&b)[N]);
    template <size_t N>
    int *setDifference(int (&a)[N], int (&b)[N]);
    template <size_t N>
    int *setSymmetricDifference(int (&a)[N], int (&b)[N]);

    template <size_t N>
    bool contains(int (&a)[N], int x)
    {
        for (int i : a)
        {
            if (i == x)
                return true;
        }
        return false;
    }

    template <size_t N, size_t M>
    void setUnion(int (&a)[N], int (&b)[M])
    {
        int k = 0;
        int u[M + N] = {};

        for (int i : a)
        {
            u[i] = i;
            k++;
            cout << " u[i]: " << u[i] << endl;
        }

        for (int i : b)
        {
            if (!contains<M + N>(u, i))
            {
                u[k] = i;
                k++;
            }
        }

        // for (int i = 0; i < m + n; i++)
        // {
        //     std::cout << u[i] << "\t";
        // }
    }

    // int *setIntersection(int (&a)[N], int (&b)[N])
    // {
    //     int m = sizeof(a) / sizeof(int);
    //     int n = sizeof(b) / sizeof(int);
    //     int l = abs(m - n);

    //     int u[l], k = 0;

    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (a[i] == b[j])
    //             {
    //                 u[k] = a[i];
    //                 k++;
    //             }
    //         }
    //     }
    //     return u;
    // }

    // int *setComplement(int (&a)[N], int (&b)[N])
    // {
    //     int *u = setUnion(a, b);
    //     return setDifference(u, a);
    // }

    // int *setDifference(int (&a)[N], int (&b)[N])
    // {
    //     int m = sizeof(a) / sizeof(int);
    //     int n = sizeof(b) / sizeof(int);
    //     int l = m > n ? m : n;
    //     int u[l], k = 0;

    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (a[i] == b[j])
    //                 break;
    //             else
    //                 u[k] = a[i];
    //         }
    //     }
    //     return u;
    // }

    // int *setSymmetricDifference(int (&a)[N], int (&b)[N])
    // {
    //     return setDifference(setUnion(a, b), setIntersection(a, b));
    // }

#ifdef __cplusplus2
}
#endif
