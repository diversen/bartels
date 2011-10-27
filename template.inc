<?php


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
</style><?php

template::setJs("http://ajax.googleapis.com/ajax/libs/jquery/1.4.3/jquery.min.js", 10);
template::setJs("http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.5/jquery-ui.min.js", 20);
template::setJs("/templates/fancybox/jquery.fancybox-1.3.3.js");

echo template::getJs();

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
<script type="text/javascript">
		$(document).ready(function() {
			/*
			*   Examples - images
			*/

			$("a#example1").fancybox({
				'titleShow'		: false,
                                'autoScale' : false,
                                'scrolling' : 'auto',
                                'autoDimensions' : false,
                                'width' : "100%",
                                'centerOnScroll' : true,
                                'opacity' : false,
                                'overlayColor' : ''
			});

			
		});
	</script>


<?php

//echo template::setMeta(); //template::$meta;

//$options = array('load_ini_file' => true);

if (!empty(register::$vars['coscms_main']['css'])){
// if (isset($row['css']) && $row['css'] != ''){
    $css = register::$vars['coscms_main']['css'];
   template::setCss("/templates/bartels/$css");
} else {
    template::setCss("/templates/bartels/common.css");
}
template::setCss('/templates/bartels/style.css?version=36', 1);
//template::setCss('/templates/fancybox/jquery.fancybox-1.3.3.css');
echo template::getCss();

/*
        include_model ('gallery');
        $galImg = new gallery(false);

        if (session::isInSession()){
            if (isset($_SESSION['gallery_count'])){
                $_SESSION['gallery_count']++;
            } else {
                $_SESSION['gallery_count'] = 0;
            }
            if ($_SESSION['gallery_count'] >= 7){
                $_SESSION['image_url'] = $galImg->getRandomImageURL();
                $_SESSION['gallery_count'] = 0;
                $_SESSION['galley_image_shift'] = 1;
            }

        } else {
            $_SESSION['gallery_count'] = 0;
            $_SESSION['image_url'] = $galImg->getRandomImageURL();
        }
*/
?>
</head>
    

<body>

    <div id="background">
<img id="background" src="<?php echo $_SESSION['image_url'];?>" />
    </div>
<div id="page">
    <div id="header">
        <?=template::getLogoHTML(array('width' => '48%')); ?>
        <div id ="top_blocks">
<?php



?>
        </div>
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

?>
</body>
</html>
<?php

}

// end of class
}
