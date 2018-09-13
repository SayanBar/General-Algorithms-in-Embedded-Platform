
# include <stdint.h>
# include <stdlib.h>

typedef struct circ_buff_t{
	uint8_t * buff;
	uint8_t * head;
	uint8_t * tail;
	uint32_t count;
	uint32_t size;
}circ_buff;

circ_buff * circ_ptr;
circ_buff * circ_pre;

typedef enum {
	FULL,EMPTY,NO,INVALID_POINTER,SUCCESS,WRAP_AROUND_SUCCESS
}rt;

int8_t is_buffer_full(circ_buff * cb1);
int8_t is_buffer_empty(circ_buff * cb1);
int8_t initialize_buffer(circ_buff * cb1, uint32_t size);
int8_t destroy_buffer(circ_buff * cb1);
int8_t add_item(circ_buff * cb1, uint8_t data);
int8_t remove_item(circ_buff * cb1);
int8_t cirbuf_peak(circ_buff*cb1, uint8_t index);




//allocates size to the buffer
int8_t CircBuf_size(circ_buff * cb1)
{
    cb1= malloc(sizeof(circ_buff));							//allocates memory in heap
    return SUCCESS;
}

//checks if buffer is full
int8_t is_buffer_full(circ_buff * cb1)
{
	return (cb1->count == cb1->size)? FULL : NO;
}


//checks if buffer empty
int8_t is_buffer_empty(circ_buff * cb1)
{
	return (cb1->count == 0)? EMPTY : NO;
}

//initializes elements of the structure
int8_t initialize_buffer(circ_buff * cb1, uint32_t size)
{
	if (!cb1)
		return INVALID_POINTER;								//null pointer check
	cb1->buff = (int8_t *)calloc(size,(sizeof(int8_t)));	//initialize memory in heap
	cb1->head = cb1->buff;									//initially head and tail point to 0th poistion
	cb1->tail = cb1->buff;
	cb1->size = size;										//size initialized to parameter passed
	cb1->count = 0;											//count = 0  initially
	return SUCCESS;
}

//used to disown the heap memory allocaed to the buffer
int8_t destroy_buffer(circ_buff * cb1)
{
	if (!cb1)												//null pointer check
		return INVALID_POINTER;
	free(cb1->buff);
	return SUCCESS;
}

//adds item to circular buffer
int8_t add_item(circ_buff * cb1, uint8_t data)
{
	if (!cb1)
		return INVALID_POINTER;								//null pointer check
	if(cb1){
		if(cb1->head==cb1->buff+cb1->size-1){				//if last position reached
			*(cb1->head)=data;								//put data in last position
			cb1->head=cb1->buff;							//reset the head to starting address
			cb1->count++;
			return WRAP_AROUND_SUCCESS;
		}
		else{
			*(cb1->head)=data;								//else enter data in next position
			cb1->head++;
			cb1->count++;
			return SUCCESS;
		}
	}
}

//remove item from circular buffer
int8_t remove_item(circ_buff * cb1)
{
	if (!cb1)
		return INVALID_POINTER;								//null pointer check
	if(cb1){
		if(cb1->tail==cb1->buff+cb1->size-1){				//if last position reached
			cb1->tail=cb1->buff;							//reset pointer to buff
			cb1->count--;
			return *(cb1->buff+cb1->size-1);				//return last position data
		}
		else{
			cb1->tail++;
			cb1->count--;
			return *(cb1->tail-1);							//else increament tail and return data
		}
	}
}

//dereference the required position and return
int8_t cirbuf_peak(circ_buff*cb1, uint8_t index)
{
    uint8_t data;
    data =  *(cb1->buff+index);								//checks the data by dereferencing the pointer at the index
    return data;
}
