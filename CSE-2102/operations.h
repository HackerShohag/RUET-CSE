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