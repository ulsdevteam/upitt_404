<?php

function upitt_404_page() {
  // this will call a couple functions to generate blocks of "help" based on where the user was coming from, what was passed to this page, or potentially even inspecting the url.
  $help_refer_url = upitt_404_help_refer_url();
  $help_target = upitt_404_help_target();
  $help_GET = upitt_404_help_GET();
  $help_POST = upitt_404_help_POST();

  $title = ($help_refer_url || $help_target || $help_GET || $help_POST) ? 'We\'re sorry that we can not find your page right now...' : '';

  return theme('upitt_404_page', array('title' => $title,
    'refer_help' => $help_refer_url,
    'target_help' => $help_target,
    'GET_help' => $help_GET,
    'POST_help' => $help_POST,
  ));
}

/**
 * This handles the block of help that may come from the referer url (where the user came from).  Depending on where the link to this page was, it may be possible to provide
 * some additional help in those cases.
 */
function upitt_404_help_refer_url() {
  module_load_include('inc', 'upitt_404', 'includes/utilities');

  $help_markup = '';
  // use the value in $_SERVER['HTTP_REFERER'];
  $refer_url = $_SERVER['HTTP_REFERER'];
  $object_pid = upitt_404_get_object_pid_from_url($refer_url);
  if ($object_pid) {
    // The $path value now potentially can be an islandora object PID
    $test_object = islandora_object_load($object_pid);
    $target_object = isset($_GET['destination']) ? islandora_object_load(upitt_404_get_object_pid_from_url($_GET['destination'])) : NULL;
    if (is_object($test_object) && !is_object($target_object)) {
      $help_markup .= '<div class="help_404_block">' . 
        '  <h4>Referring Page Help</h4>' . 
        '  <p>The page that you came from "' . l($test_object->label, '/islandora/object/' . $object_pid . '/viewer') . '" currently has a link to an object in the system that has not yet been integrated with the website.  ' . 
        '    This is a known issue for finding aids and we\'re working hard to connect all of the objects with all of the data.</p>' . 
        '  <p>Click here to go "<a href="javascript:history.back()">Back</a>" <i>(this only works when page was opened in the same Tab)</i>.</p>' .
        '</div>';
    }
  }
  return $help_markup;
}

/**
 * This handles the block of help that may come from the target url destination.  Many times this will be blank, but there may
 * be cases where some info could be provided.
 */
function upitt_404_help_target() {
  $help_markup = '';
  // use the value in $_GET['destination'] since this is passed to the 404 handler.

  // example block
  $help_markup = '<div class="help_404_block">' .
        '  <h4>Info on the target URL</h4>'.
        '  <p>Demo of helpful info derived by inspecting the target uri</p>' . 
        '</div>';

  return $help_markup;
}

/**
 * This handles the block of help that may come from the target url destination, but only looks at the query string that is at the end of the URL.
 */
function upitt_404_help_GET() {
  $help_markup = '';
  // use the values in $_GET -- they may be at the end of the $_GET['destination'] url as a query string.

  // example block
  $help_markup = '<div class="help_404_block">' .
        '  <h4>Info on the _GET uri</h4>'.
        '  <p>Demo of helpful info derived by inspecting the _GET uri</p>' .
        '</div>';

  return $help_markup;
}

/**
 * This handles the block of help that may come from $_POST variables from the intended page.  This may not be able to provide any help.
 */
function upitt_404_help_POST() {
  $help_markup = '';

  // example block
  $help_markup = '<div class="help_404_block">' .
        '  <h4>Info on the _POST uri</h4>'.
        '  <p>Demo of helpful info derived by inspecting the _POST uri</p>' .
        '</div>';

  return $help_markup;
}

