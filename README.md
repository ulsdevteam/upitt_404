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
####'refer_help'
####'target_help'
####'GET_help'
####'POST_help'
