/** @file
 * Button input handler.
 */
#include "input.h"

enum ButtonAction : uint8_t {
  None = 0,
  Press = 1,
  LongPress = 2,
};

/**
 * Base class for handling input from a hardware button.
 *
 * Implementations of this class are able to respond to several different
 * gestures:
 * - a simple press: onButtonPressed
 * - a long press: onLongPress
 * - a continuous long press: onLongPressHeld
 *
 * ...or simple changes in state:
 * - any change in the button status: onButtonToggle
 * - button pressed down: onButtonDown
 * - button released: onButtonUp
 */
class AbstractButtonHandler : AbstractInputHandler {
 public:
  /// How long (milliseconds) does a button need to be pressed to count as a
  /// press)
  static const int MIN_PRESS_DURATION = 50;

  /// How long (milliseconds) does a button need to be pressed to count as a
  /// long press
  static const int LONG_PRESS_DURATION = 600;

  AbstractButtonHandler(uint8_t pin) : AbstractInputHandler(pin) {}

  /**
   *  Triggered when button is released after being pressed for
   *  a duration between MIN_PRESS_DURATION and LONG_PRESS_DURATION
   *  i.e. a simple press and release
   */
  virtual void onButtonPressed(void) = 0;

  /// Triggered once when the button is held down for LONG_PRESS_DURATION
  virtual void onLongPress(void) {}

  /// Triggered before onButtonDown and onButtonUp
  virtual void onButtonToggle(void) {}

  /// Triggered once when the button is pressed down
  virtual void onButtonDown(void) {}

  /// Triggered once when the button is released
  virtual void onButtonUp(void) {}

  /// Triggered continuously for as long as the button is held after
  /// LONG_PRESS_DURATION
  virtual void onLongPressHeld(void) {}

  /// Allow other inputs to change their behaviour by reading the state of this
  /// button.
  bool isDown(void) const { return action_started_timestamp_ != 0; }

  /**
   * Mark the current action as consumed so it will not trigger any further callbacks.
   */
  void consumeAction(void) {
    if (isDown()) {
      action_consumed_ = true;
    }
  }

  bool isActionConsumed() const {
    return action_consumed_;
  }

  /// Called in arduino setup() function
  void setup(void) {
    setPinMode(INPUT);
    // writeDigital(HIGH);
  }

  /// Called in arduino loop() function
  void update(void) {
    current_value_ = !readDigital();
    current_timestamp_ = getTimestamp();

    if (current_value_ != previous_value_) {
      updateWithNewState();
    } else if (action_started_timestamp_ > 0) {
      updateWithContinuingState();
    }

    previous_value_ = current_value_;
    current_timestamp_ = 0;
  }

 protected:
  uint8_t action_ = ButtonAction::None;
  bool previous_value_ = false;
  bool current_value_ = false;

 private:
  unsigned long action_started_timestamp_ = 0;  ///< When did the current button press start
  unsigned long current_timestamp_ = 0;  ///< What time is it now?
  unsigned long action_duration_ = 0;  // Difference between current_timestamp_ and  action_started_timestamp_
  bool action_consumed_ = false;

  /**
   * Handle the case where the button state has changed (pushed/released) since
   * the previous update cycle.
   */
  void updateWithNewState(void) {
    onButtonToggle();
    if (current_value_ == true) {
      action_started_timestamp_ = getTimestamp();
      onButtonDown();
    } else if (current_value_ == false) {
      if (!action_consumed_) {
        // Trigger callbacks only if this action has not been consumed.
        if (action_ == ButtonAction::Press) {
          onButtonPressed();
        }
        onButtonUp();
      }
      // Reset action-tracking variables.
      action_ = ButtonAction::None;
      action_started_timestamp_ = 0;
      action_duration_ = 0;
      action_consumed_ = false;
    }
  }

  /**
   * Handle the case where the button is in the same state as the previous
   * update cycle.
   */
  void updateWithContinuingState(void) {
    if (action_consumed_) {
      // The action has been cancelled by something else.
      return;
    }

    action_duration_ = current_timestamp_ - action_started_timestamp_;
    if (action_duration_ > LONG_PRESS_DURATION) {
      // The button has been down for a long time.
      if (action_ == ButtonAction::None || action_ == ButtonAction::Press) {
        onLongPress();
        action_ = ButtonAction::LongPress;
      } else {
        onLongPressHeld();
      }
    } else if (action_duration_ > MIN_PRESS_DURATION) {
      // The button has been down for a short time.
      action_ = ButtonAction::Press;
    }
  }
};
