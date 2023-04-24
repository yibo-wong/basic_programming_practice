char c;
c = getchar();
/*do something with c*/
while(c != '\n' && c != '\r') {
c = getchar();
/* do something with c */
}
while(c == '\n' || c=='\r') c = getchar();
while(c != '\n' && c != '\r') {
c = getchar();
if(c == EOF) break;
/* do something with c */
}
