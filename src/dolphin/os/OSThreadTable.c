extern unsigned int *lbl_801A6744;

#pragma push
#pragma force_active on

unsigned int fn_80009FA4(int index)
{
    return *(unsigned int *)((char *)lbl_801A6744 + index * 12);
}

unsigned int fn_80009FB4(unsigned int *ptr)
{
    return *(unsigned int *)((char *)ptr - 24);
}

#pragma pop
