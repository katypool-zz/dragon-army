<?php

require_once 'includes/custom_menu.inc';

function planetta_page_alter($page) {

    $viewport = array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
            'name' => 'viewport',
            'content' => 'width=device-width, initial-scale=1, maximum-scale=1'
        )
    );
    drupal_add_html_head($viewport, 'viewport');
}

function planetta_html_head_alter(&$head_elements) {
    $head_elements['system_meta_content_type']['#attributes'] = array(
        'charset' => 'utf-8'
    );
}

function planetta_preprocess_page(&$vars) {
    $custom_main_menu = _custom_main_menu_render_superfish();
    if (!empty($custom_main_menu['content'])) {
        $vars['navigation'] = $custom_main_menu['content'];
    }
    $planetta_mobile_message = theme_get_setting('planetta_mobile_message', 'planetta');
    $vars['mobile_message'] = $planetta_mobile_message;
}

function planetta_process_html(&$variables) {
    if (arg(0) != 'admin' || !(arg(1) == 'add' && arg(2) == 'edit') || arg(0) != 'panels' || arg(0) != 'ctools') {
        $scripts = drupal_add_js();
        $new_jquery = array('sites/all/themes/planetta/js/jquery/jquery.js' => $scripts['misc/jquery.js']);
        $new_jquery['sites/all/themes/planetta/js/jquery/jquery.js']['data'] = 'sites/all/themes/planetta/js/jquery/jquery.js';
        $scripts = array_merge($new_jquery, $scripts);
        unset($scripts['misc/jquery.js']);
    }

    $variables['scripts'] = drupal_get_js('header', $scripts);
}

/**
 * Returns HTML for a breadcrumb trail.
 *
 * @param $variables
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */
function planetta_breadcrumb($variables) {
    $breadcrumb = $variables['breadcrumb'];

    if (arg(0) && arg(0) == 'node') {
        if (is_numeric(arg(1))) {
            $nid = arg(1);
            $node = node_load($nid);

            if (isset($node->type) && $node->type == 'blog') {
                $breadcrumb[] = l('Blog', 'blog');
            }
            if (isset($node->type) && $node->type == 'portfolio') {
                $breadcrumb[] = l('Portfolio', 'portfolio');
            }
			
			if (isset($node->type) && $node->type == 'consultant') {
                $breadcrumb[] = l('Consulting', 'consulting');
            }
			
			if (isset($node->type) && $node->type == 'training') {
                $breadcrumb[] = l('Training', 'training');
            }
			
			if (isset($node->type) && $node->type == 'campus_resources') {
                $breadcrumb[] = l('Campus Resources', 'dlab-campus-resources');
            }
			
			if (isset($node->type) && $node->type == 'data_resources') {
                $breadcrumb[] = l('Data Resources', 'data-resources');
            }
			
			if (isset($node->type) && $node->type == 'event') {
                $breadcrumb[] = l('Event List', 'event-list');
            }
			
			if (isset($node->type) && $node->type == 'page') {
                $breadcrumb[] = l('Home', null);
            }
			
			if (isset($node->type) && $node->type == 'contactus') {
                $breadcrumb[] = l('Home', null);
            }
			
			if (isset($node->type) && $node->type == 'staff') {
                $breadcrumb[] = l('Home', null);
            }
			
			if (isset($node->type) && $node->type == 'support_ticket') {
                $breadcrumb[] = l('Support Ticket List', 'support-ticket-list');
            }
			
			
        }
    }

    if (!empty($breadcrumb)) {
        $output = '';
        $br = $breadcrumb[(count($breadcrumb) - 1)];
        $br = str_replace('<a ', '<a class="back"', $br);
        $output .= $br;
        return $output;
    }
}

/**
 * SUPPORT TICKET BUTTON | CUSTOM EDIT - C. Church 1/21/13
 * Changes the SAVE button to SUBMIT on the edit form
 */

function planetta_form_alter(&$form, $form_state, $form_id) {
	if($form_id=="support_ticket_node_form") {
		$form['actions']['submit']['#value'] = t('Submit');
		drupal_set_title('Contact Us');
		$breadcrumb[] = l('Home', null);
		drupal_set_breadcrumb($breadcrumb);
		
		if (isset($_GET['subject'])) {$subject = $_GET['subject']; //ACCEPTS a SUBJECT FROM THE URL
		$form['title']['#attributes']['value'] = $subject;}
	}


	if($form_id=="registration_node_form") {
		$form['actions']['submit']['#value'] = t('Submit');
		drupal_set_title('Register');
		$breadcrumb[] = l('Home', null);
		drupal_set_breadcrumb($breadcrumb);
	}

	/**
	*CANCEL/RESTORE REGISTRATION BUTTONS | CUSTOM EDIT - K. Pool 4/16/2014
	*Changes the SUBMIT button to 'Cancel this registration' and CANCEL to 'nevermind' when cancelling registration
	*Changes the SUBMIT button to 'Restore this registration' and CANCEL to 'nervemind' when uncancelling registration
	*/
	if($form_id=="flag_confirm") {
		if($form['flag_name']['#value']=="cancel_registration" && $form['action']['#value']=="flag"){
			$form['actions']['submit']['#value'] = t('Cancel this registration');
			$form['actions']['cancel']['#title'] = t('Nevermind');
		}
		if($form['flag_name']['#value']=="cancel_registration" && $form['action']['#value']=="unflag"){
			$form['actions']['submit']['#value'] = t('Restore this registration');
			$form['actions']['cancel']['#title'] = t('Nevermind');
		}
	}

		/*	NOTE: the following is commented out because it was made unnecessary by the Entity Reference and Entity Reference Prepopulate Modules - C. Church - 02/15/13
				if (isset($_GET['event'])) {$event = $_GET['event'];  //ACCEPTS a SUBJECT FROM THE URL
				$form['title']['#attributes']['value'] = $event;
				$form['title']['#attributes']['readonly'] = 'readonly'; }
				
				if (isset($_GET['time'])) {$time = $_GET['time'];	 //ACCEPTS a TIME FROM THE URL
				$form['field_event_time']["und"][0]['value']['#default_value']=$time;
				$form['#after_build'][] = '_planetta_after_build'; }
				
				if (isset($_GET['type'])) {$type = $_GET['type'];  //ACCEPTS a TYPE FROM THE URL
					$form['field_register_type']["und"][0]['value']['#default_value']=$type;
					$form['#after_build'][] = '_planetta_after_build';
					}
				if (isset($_GET['uid'])) {$uid = $_GET['uid'];  //ACCEPTS a UID FROM THE URL
					$form['field_training_uid']["und"][0]['value']['#default_value']=$uid;
					$form['#after_build'][] = '_planetta_after_build';
				}
			*/	

}
 
/*	NOTE: the following is commented out because it was made unnecessary by the Entity Reference and Entity Reference Prepopulate Modules - C. Church*/
		/*AFTER BUILD FUNCTIONS THAT MAKE CCK TIME FIELD ON THE REGISTER FORM READ ONLY - C. CHurch - 02-08-13*/
				/**
				* Custom after_build callback handler.
				
				function _planetta_after_build($form, &$form_state) {
				  // Use this one if the field is placed on top of the form.
				  if (isset($_GET['time'])) {_planetta_fix_readonly($form['field_event_time']);}
				  if (isset($_GET['type'])) {_planetta_fix_readonly($form['field_register_type']);}
				  if (isset($_GET['uid'])) {_planetta_fix_readonly($form['field_training_uid']);}
				  // Use this one if the field is placed inside a fieldgroup.
				//  _mysnippet_fix_readonly($form['group_mygroup']['field_myfield']);
				  return $form;
				}

				/**
				* Recursively set the readonly attribute of a CCK field
				* and all its dependent FAPI elements.
				
				function _planetta_fix_readonly(&$elements) {
				  foreach (element_children($elements) as $key) {
					if (isset($elements[$key]) && $elements[$key]) {

					  // Recurse through all children elements.
					  _planetta_fix_readonly($elements[$key]);
					}
				  }

				  if (!isset($elements['#attributes'])) {
					$elements['#attributes'] = array();
				  }
				  $elements['#attributes']['readonly'] = 'readonly';
				}
		*/
?>