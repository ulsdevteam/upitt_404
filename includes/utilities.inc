<?php 

/**
 * Helper function to parse a url and return the islandora PID value that it represents if possible.
 */
function upitt_404_get_object_pid_from_url($url) {
  $pid = '';
  $url_parts = parse_url($url);
  if (isset($url_parts['path'])) {
    $path = ltrim($url_parts['path'], '/');
    // Can this url represent the PID of an object in the islandora system?
    if (strstr($path, 'islandora/object/')) {
      $path = str_replace("islandora/object/", "", $path);
      // if the url has any extra handler like "/viewer", strip that off the tail.
      if (strstr($path, '/')) {
        $parts = explode("/", $path);
        $pid = urldecode($parts[0]);
      }
    }
  }
  return $pid;
}

