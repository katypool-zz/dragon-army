dragon-army
===========
This is a collection of features for the d-lab site [dlab.berkeley.edu](http://dlab.berkeley.edu) including:  

+ Consultation Request Forms: automatically creates a consultation request webform every time a new consultation is added to the site.  

+ Course Feeds Importer: imports a CSV of UC Berkeley courses to be added to D-Lab's [course list](http://dlab.berkeley.edu/course-list).  

+ People Panels: displays panel panes of workshops, consultations, and trainings associated with all D-Lab staff, consultants, and instructors. [Example](http://dlab.berkeley.edu/people/zawadi-rucks-ahidiana)  

+ Reminder E-mails: automatically sends out reminder e-mails to users registered for D-Lab trainings.  

+ Template.php file: lines 145-155 contain a sample of PHP implemented by Katy Pool on the D-Lab dev site. 

This repo also includes the D-Lab Basic Architecture feature, which contains all content types and taxonomies on the D-Lab site, some of which the above features are dependent on.    

-------
Below is a brief description of my contributions to the above projects:  

+ Consultation Request Forms: The client wanted 3 things --  
     1. A consultation request form for each individual consultant, which would automatically e-mail them with new requests  
     2. A general consultation request form for users who did not know which individual consultant to contact  
     3. A way to assign these general consultation requests to specific consultants  
I worked with Rochelle to create a new webform template for consultation requests and then, using the Webform share module, added the web form default components to the content type 'consultation.' A web form was automatically created every time a new consultation was added, pulling fields from the content type 'consultation.' We already had a content type 'support ticket' which allowed site users to create a node for their general consultation requests. We added the flag 'status' that allowed the support ticket to be flagged 'assigned' and 'unassigned' by our content managers. Matt Cheney wrote us a module called 'DLAB webform assign' which automatically converted general consultation 'support tickets' into webform submissions for a specific consultant when assigned to them.  

======

+ Course Feeds Importer: The content type for courses and the course list view were already in place on the site. I created the course feeds importer and wrangled a huge CSV file of courses to add to the site.  

=====

+ People Panels: One of the first projects I took the lead on. I created the panel panes displays from scratch using contextual filters and then implemented the mini-panels module to create a block for every D-Lab person page. I also applied CSS tweaks.  

====

+ Reminder E-mails: The client had a similar reminder e-mail system in place that automatically sent out e-mails 24 hours before the training was scheduled. I backwards engineered a new reminder e-mail rule with its own components and VBO to send out reminder e-mails 72 hours before each training.

