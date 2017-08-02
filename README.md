# upitt_404
## University of Pittsburgh 404 page handler

This module will set up a handler for a menu route "404_page".  When possible, this will
redirect the user to the correct page, but will display helpful links and info when a 
redirect has been created.

### Logging 404 URLs and Training redirects 
When the URL does not lead to an object, it is logged in the upitt_404 table in the 
database.  The address is relative to the given site's domain, so these redirects could 
be exported to be used with a different site (if that makes sense).  This is all managed
via the Admin | UPitt 404 | Report.


### Helpful info
The info is broken down into four main groups.
#### 'refer_help'
Info may come from the referer url (where the user came from).  Depending on where the link to this page was, it may be possible
to provide some additional help in those cases.  This inspects the value of `$_SERVER['HTTP_REFERER']`.
> pending development

#### 'target_help'
Info comes from the target url destination.  Many times this will be blank, but there may be cases where some info could be provided.  This will inspect the value of `$_GET['destination']` since that is passed to the 404 handler by the drupal code and this module code.
> pending development

#### 'GET_help'
Info comes from the target url destination, but only looks at the query string that is at the end of the URL.  This also inspects the use the values in $_GET they may be at the end of the `$_GET['destination']` url as a query string.
> pending development

#### 'POST_help'
Info comes from $_POST variables from the intended page.  This may not be able to provide any help.
> pending development
