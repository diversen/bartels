<?php

define('HTML_FORM_TEXT_SIZE', 30);
define('HTML_FORM_MAX_FILE_SIZE', 1048576); // 1 MB
define('HTML_FORM_PASSWD_SIZE', 8);
define('HTML_FORM_TEXTAREA_WT', 40);
define('HTML_FORM_TEXTAREA_HT', 10);
define('HTML_FORM_TH_ATTR', 'align="right" valign="top"');
define('HTML_FORM_TD_ATTR', '');
define('MENU_LIST_START', '<ul>');
define('MENU_LIST_END', '</ul>');
define('MENU_SUBLIST_START', '<li>');
define('MENU_SUBLIST_END', '</li>');
define('MENU_SUB_SEPARATOR', '| ');


function get_form_element_start($name, $title = '&nbsp;'){
    $str = "<label for=\"$name\">$title</label><br />\n";
    return $str;
}


function get_form_element_end(){
    $str = "<br />\n";
    return $str;
}


function view_form_start($caption){
    $str = "<fieldset>";
    if ($caption) {
        $str.= "<legend>" . $caption . "</legend>";
    }
    print $str;

}


function view_form_end(){
    print "</fieldset>\n";
}
/**
 *
 * @param <array> $errors errors to display on wrong form submit
 */
function view_form_errors($errors){ 
    if (is_string($errors)){
        view_error($errors);
        return;
    }
    
    ?>
<!-- form_error -->
<div id="form_error">
<ul>
<?php
    foreach($errors as $error){ ?>
<li><?php echo $error?></li>
<?php  } ?>
</ul>
</div>
<!-- / end form_error -->
<?php

}

/**
 *
 * @param <string> $message positive confirmation on correct filled form
 */
function view_confirm($message){ ?>
<!-- view_confirm -->
<div id="form_confirm">
<ul><li><?php echo $message?></li></ul>
</div>
<?php

}

function view_error($message){ ?>
<!-- view_confirm -->
<div id="form_error">
<p><?php echo $message?></p>
</div>
<?php

}
// prints a topline message on page
function headline_message($message){ ?>
<!-- view_confirm -->
<div id="headfont">
<?php echo $message?>
</div>
<?php

}