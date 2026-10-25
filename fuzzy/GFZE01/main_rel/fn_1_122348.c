/* Non-matching: best partial attempt (86.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
extern const f32 lbl_1_rodata_7B1C;
extern const f32 lbl_1_rodata_7B20[14];
extern void fn_1_10846C(void *);
extern void fn_1_128884(void *, void *, int);
typedef struct {
 u8 active; u8 pad_1[15]; f32 value; u8 pad_14[4];
 f32 weight; u8 pad_1c[36]; f32 result;
} Entry;
typedef struct {u8 pad[0x8c]; s32 kind;} Owner;
typedef struct {
 u8 pad[12]; Owner *owner; u8 pad10[8]; s32 count;
 u8 pad1c[8]; Entry *entries;
} Data;
#pragma opt_dead_assignments off
static inline void fn_1_122348_loop5(s32 n, Data *data) {
 u32 j;
 Entry *q;
 Entry *p;
 u32 i;
 p=data->entries;
 for(i=0;i<n;i++,p++) {
 for(j=((1) + (i)),q=((1) + (p));j<n;j++,q++) {
 if(p->weight>q->weight) fn_1_128884(p,q,68);
 }
 }
}

static inline f32 fn_1_122348_read_pointer(Entry * owner) { return owner->weight; }
void fn_1_122348(Data *data, u32 lab_unused0, u32 lab_unused1) {
 u32 k;
 Entry *entry2;
 u32 rounds;
 u32 cnt;
 Entry *q;
 struct { u32 value; } j;
 u32 i;
 s32 n;
 u32 choice;
 s32 pos;
 Entry *p2;
 Entry * p_2;
 Entry *entry;
 Entry *p;
 if (data) {
 choice=13;
 if(data->owner->kind==2) choice=9;
 n=choice;
 fn_1_10846C(data);
 entry=data->entries;
 i=0;
 while(i<data->count) {
 if(entry->active&1) {entry->active=0;entry->result=lbl_1_rodata_7B1C;}
 else {entry->active=1;entry->result=lbl_1_rodata_7B20[0];}
 i++;entry++;
 }
 p=data->entries;
 for(i=0;i<data->count;i++,p++) {
 for(q=data->entries+i+1,j.value=i+1;j.value<data->count;j.value++,q++) {
 if(p->active==0 && q->active!=0) fn_1_128884(p,q,68);
 }
 }
 p_2=data->entries;
 for(i=0;i<data->count;i++,p_2++) {
 for(q=data->entries+i+1,j.value=i+1;j.value<data->count;j.value++,q++) {
 if(p_2->active==q->active && p_2->value<q->value) fn_1_128884(p_2,q,68);
 }
 }
 fn_1_122348_loop5(n, data);
 p_2=data->entries+n;
 for(i=n;i<n*2;i++,p_2++) {
 for(j.value=i+1,q=p_2+1;j.value<n*2;j.value++,q++) {
 if(p_2->weight>q->weight) fn_1_128884(p_2,q,68);
 }
 }
 entry2=data->entries;
 cnt=data->count;
 for(i=0;i<cnt;i++) {
 if(entry2->active!=0 && entry2[1].active==0) break;
 entry2++;
 }
 entry2++;
 pos=entry2-data->entries;
 rounds=(data->count-pos)/n;
 for(k=0;k<rounds;k++) {
 for(j.value=0;j.value<n;j.value++) entry2[j.value].result=-(f32)(k+1)/(f32)(rounds+1);
 p2=entry2;
 for(i=0;i<n;i++,p2++) {
 for(j.value=i+1,q=p2+1;j.value<n;j.value++,q++) {
 if(p2->weight>fn_1_122348_read_pointer(q)) fn_1_128884(q,p2,68);
 }
 }
 entry2+=n;
 }
 }
}
