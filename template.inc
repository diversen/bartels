<?php

template::init('bartels');

class mainTemplate extends template {

/**
 * method for printing out template header
 *
 * @param  array    assoc array containing current page info
 */
public static function printHeader(){ ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"> 
<html lang="<?=register::$vars['coscms_main']['lang']?>">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<!--
	This website is powered by coscms
	coscms is a small open source Content Management Framework initially created by Dennis Iversen and licensed under BSD.
	Information and contribution at http://coscms.org
        Need a website? Contact: dennis.iversen@gmail.com
-->

<title><?php echo $_SERVER['HTTP_HOST']?> :: <?php echo template::getTitle(); ?></title>
<style type="text/css">
        font-face {
            font-family: "Flama-Semibold";
            src: url(http://<?php echo $_SERVER['HTTP_HOST']; ?>/templates/bartels/Flama-Semibold.otf) format("opentype");
        }
</style>
               <!-- <link rel="stylesheet" type="text/css" href="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.9/themes/ui-lightness/jquery-ui.css" />-->
<link rel="stylesheet" type="text/css" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.9/themes/hot-sneaks/jquery-ui.css" />

    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.5.0/jquery.min.js"></script>
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.9/jquery-ui.js"></script>


            <?php





?>
<script type="text/javascript">

$(document).ready(function() {
  var toggle = function(direction, display) {
    return function() {
      var self = this;
      var ul = $("ul", this);
      if( ul.css("display") == display && !self["block" + direction] ) {
        self["block" + direction] = true;
        ul["slide" + direction]("slow", function() {
          self["block" + direction] = false;
        });
      }
    };
  }
  $("li.menu").hover(toggle("Down", "none"), toggle("Up", "block"));
  $("li.menu ul").hide();
});

</script>



<?php

echo template::getMeta();

template::setTemplateCss('bartels');
template::setCss('http://fonts.googleapis.com/css?family=Rancho');
echo template::getCss();
echo template::getInlineCss();

include_model ('gallery');
$bg_image = gallery::getShiftingImageURL();

?>
</head>
    

<body>
    <div id="background">
<img id="background" src="<?php echo $bg_image;?>" />
    </div>
<div id="page">
    <?php if (session::isAdmin()) { ?>
    <div id="system_admin_menu">
            <?php
$blocks = layout::getBlock('blocks_top');
                foreach ($blocks as $key => $val){
                    echo $val;
                }

?>

    </div>
    <?php } ?>
    <div id="header">        
        <?=template::getLogoHTML(array('width' => '48%', 'font' => 1)); ?>

    </div>

    <div id="sidebar_cheat">&nbsp;</div>
    <div id="sidebar_left">

<?php

$blocks = layout::getBlock('blocks');
            foreach ($blocks as $key => $val){
                print $val;
            }
?>
    </div>
    <div id="sidebar_right">
        <?php
        


        ?>
   </div>
    <div id="content">
        <div id="module_menu">
<?php

echo layout::getModuleMenu();

?>
        </div>
        <div id="system_message"><p>
<?php

echo session::getActionMessage();

?>
        </p></div>

<?php

}

/**
 * method for print footer of page
 */
public static function printFooter(){


?>
        <div id="end_content">
<?php

echo template::getEndContent();

?>
        </div>
    </div>
    <div id="footer">
    <?php /* echo $_COS_MAIN['footer_message'] */ ?>
    </div>
</div>
<?php

//echo template::getEndHTML();

echo template::getJs();
echo template::getInlineJs();

?>
</body>
</html>
<?php

}

// end of class
}
