struct stack *sp;
  sp->size = len;
  sp->top =-1;
  sp->arr =(char*)malloc(len * sizeof(char));
