//instanalize an instance of 'tap' for the 'lshft' tap dance.
static tap lshft_tap_state = {
  .is_press_action = true,
  .state = 0
};

void lshft_finished (qk_tap_dance_state_t *state, void *user_data) {
  lshft_tap_state.state = current_dance(state);
  switch (lshft_tap_state.state) {
    case SINGLE_TAP: register_code(KC_9); break;
    case SINGLE_HOLD: register_code(KC_LSHIFT); break;
    case DOUBLE_HOLD:
    case DOUBLE_TAP: register_code(KC_LBRACKET); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void lshft_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (lshft_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_9); break;
    case SINGLE_HOLD: unregister_code(KC_LSHIFT); break;
    case DOUBLE_HOLD:
    case DOUBLE_TAP: unregister_code(KC_LBRACKET); break;
  }
  lshft_tap_state.state = 0;
}

// instanalize an instance of 'tap' for the 'lshft' tap dance.
static tap rshft_tap_state = {
  .is_press_action = true,
  .state = 0
};

void rshft_finished (qk_tap_dance_state_t *state, void *user_data) {
  rshft_tap_state.state = current_dance(state);
  switch (rshft_tap_state.state) {
    case SINGLE_TAP: register_code(KC_0); break;
    case SINGLE_HOLD: register_code(KC_RSHIFT); break;
    case DOUBLE_HOLD:
    case DOUBLE_TAP: register_code(KC_RBRACKET); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void rshft_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (rshft_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_0); break;
    case SINGLE_HOLD: unregister_code(KC_RSHIFT); break;
    case DOUBLE_HOLD:
    case DOUBLE_TAP: unregister_code(KC_RBRACKET); break;
  }
  rshft_tap_state.state = 0;
}