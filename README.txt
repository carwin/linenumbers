
-- SUMMARY --

Nodelines is a field formatter for Long Text fields which adds line 
numbering to content.

This module is useful when implementations Syntax highlighter and 
Geshi Filter are overkill and all you need is numbered lines for 
something simple.

For a full description of the module, visit the project page:
  http://drupal.org/sandbox/carwin/1789542

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/node/add/project-issue/1789542 


-- REQUIREMENTS --

None.


-- INSTALLATION --

* Install as usual, 
  see http://drupal.org/documentation/install/modules-themes/modules-7 
  for further information.


-- CONFIGURATION --

None.

-- CUSTOMIZATION --

None.

-- TROUBLESHOOTING --

* If the formatter does not display, check the following:

  - The module is enabled.

  - The cache has been cleared. 


-- FAQ --

Q: All the content I input into this formatter comes out wrapped in a <pre>
   tag. Why?

A: Currently, everything is wrapped in a <pre> tag to improve the display
   of content after it has been passed through the Nodelines formatter.
   Each line of text is prepended with it's line number so that the number
   becomes part of the text. This is not a permanent situation.


-- CONTACT --

Current maintainers:
* Carwin R. Young (carwin) - http://drupal.org/user/487058
