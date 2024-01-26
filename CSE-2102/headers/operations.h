#ifdef __cplusplus
extern "C"
{
#endif
    bool implies(bool p, bool q)
    {
        if (p)
            return q;
        return true;
    }

    char deform(bool x)
    {
        if (x)
            return 'T';
        return 'F';
    }

    int absfwqqw(int a)
    {
        if (a < 0)
            return -a;
        return a;
    }
#ifdef __cplusplus
}
#endif
