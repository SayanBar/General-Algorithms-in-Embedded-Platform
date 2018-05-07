#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


uint8_t* buff_initialize(circbuff *buffer)
{
	buffer= malloc(sizeof(circbuff));
	uint8_t *new = (uint8_t*) calloc(1 , sizeof(uint8_t));
	buffer->head=new;
	buffer->tail=new;
	buffer->start=new;
	buffer->no_items= 0;
	buffer->length = MAX;
    return buffer->start;
}

void buff_unallocate(circbuff *cb1)
{
	free(cb1);
}

buf_state buff_full(circbuff *cb1)  // Function checks if the buffer is full or not
{
    if (cb1->no_items == cb1->length)
    {   // If the head is at the end of the buffer and tail is at the start then buffer is full
        //or if head is one position behind the tail then also buffer is full
        return buffer_is_full;
    }
    else
    {
        return buffer_is_not_full;
    }

}

buf_state buff_empty(circbuff *cb1)
{
    // if head and tail of the buffer are at the same position then that means buffer is empty.
    if(cb1->no_items==0)
    {
        return buffer_is_empty;
    }
    else
    {
        return buffer_is_not_empty;
    }
}

buf_state buff_add(circbuff *cb1, uint8_t item)
{

    buf_state code;
    code=buff_full(cb1);  // before adding new item it checks if buffer is full or not
    if(code==buffer_is_not_full)
    {
        if(cb1->head==(cb1->start)+(cb1->length)-1)
        {
          cb1->head=cb1->start;
        *(cb1->head)=item;
        (cb1->no_items)++;
        return add_to_buffer_success_with_wrap_around;
        }

        else
        {      	// otherwise add the item at the location of head and then head++
            cb1->head++;
            *(cb1->head)=item;
            (cb1->no_items)++;
            return add_to_buffer_success;

        }


    }
    else if(code==buffer_is_full)
    { // If buffer is full , do not add item and return error
      return buffer_is_full;
    }

}

uint8_t buff_remove(circbuff *cb1)
{
    buf_state code;
	uint8_t rd;
    code=buff_empty(cb1);  // check for buffer empty before removing item
    if(code==buffer_is_not_empty)
    {

        if(cb1->tail==((cb1->start)+(cb1->length))-1)
        {  // if tail is at the last position of the buffer then remove the item there
         //and then put tail at the base address of the buffer

        cb1->tail=cb1->start;
		rd=*(cb1->tail);
        *(cb1->tail)=0;
        (cb1->no_items)--;
        return rd;
        }

        else
        {  // otherwise remove the item at the location of tail and then do tail++
            (cb1->tail)++;
			rd=*(cb1->tail);
            *(cb1->tail)=0;
            (cb1->no_items)--;
            return rd;

        }
    }
    else if(code==buffer_is_empty)
    { // If buffer is empty , do not remove item and return error
      return -1;
    }
}

