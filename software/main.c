#include "ch.h"
#include "hal.h"

static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palSetPad(GPIOA, 1);
    chThdSleepMilliseconds(500);
    palClearPad(GPIOA, 1);
    chThdSleepMilliseconds(500);
  }
}

int main(void) {
  halInit();
  chSysInit();

  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO+1, Thread1, NULL);

  while (true) {
    chThdSleepMilliseconds(1000);
  }
}
