<?php
/**
 * @file
 * consultation_request.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function consultation_request_default_rules_configuration() {
  $items = array();
  $items['rules_status_flag_support_ticket'] = entity_import('rules_config', '{ "rules_status_flag_support_ticket" : {
      "LABEL" : "Status Flag - Support Ticket Resolved",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_flagged_status" ],
      "IF" : [
        { "entity_has_field" : { "entity" : [ "flagged-node" ], "field" : "field_ticket_status" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "flagged-node:field-ticket-status" ], "value" : "99" } }
      ]
    }
  }');
  $items['rules_status_flag_support_ticket_unesolved'] = entity_import('rules_config', '{ "rules_status_flag_support_ticket_unesolved" : {
      "LABEL" : "Status Flag - Support Ticket Unesolved",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : [ "flag_unflagged_status" ],
      "IF" : [
        { "entity_has_field" : { "entity" : [ "flagged-node" ], "field" : "field_ticket_status" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "flagged-node:field-ticket-status" ], "value" : "98" } }
      ]
    }
  }');
  $items['rules_support_ticket_email'] = entity_import('rules_config', '{ "rules_support_ticket_email" : {
      "LABEL" : "Support Ticket Email",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "support_ticket" : "support_ticket" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "dlab-consultants@lists.berkeley.edu",
            "subject" : "Support Ticket #[node:nid] - [node:title] | [node:field-ticket-user-name]",
            "message" : "Ticket #[node:nid]\\r\\nTitle: [node:title]\\r\\nName: [node:field-ticket-user-name]\\r\\nEmail: [node:field-ticket-user-email]\\r\\nMessage: [node:body]\\r\\n\\r\\nTo assign this ticket, click here: http:\\/\\/dlab.berkeley.edu\\/support-ticket-list\\/assign\\/[node:nid]\\r\\n",
            "from" : "[site:mail]",
            "language" : [ "node:type" ]
          }
        },
        { "redirect" : { "url" : "thank-you" } }
      ]
    }
  }');
  return $items;
}
