

#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_



unsigned char Get_Data();
void subscribe(void (*ptr)(unsigned char));
void unsubscribe(int *Y);
void notify();

#endif /* INC_DEVICE_H_ */
