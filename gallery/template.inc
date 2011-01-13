<?php

class mainTemplate extends template {

/**
 * method for printing out template header
 *
 * @param  array    assoc array containing current page info
 */
public static function printHeader(){ ?>
<!doctype html>
<html lang="<?=register::$vars['coscms_main']['lang']?>">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title><?php echo $_SERVER['HTTP_HOST']?> :: <?php echo template::getTitle(); ?></title>
<style type="text/css">
        font-face {
            font-family: "Flama-Semibold";
            src: url(http://<?php echo $_SERVER['HTTP_HOST']; ?>/templates/bartels/Flama-Semibold.otf) format("opentype");
        }
</style>
<?php

echo template::$meta;

//$options = array('load_ini_file' => true);

if (!empty(register::$vars['coscms_main']['css'])){
// if (isset($row['css']) && $row['css'] != ''){
    $css = register::$vars['coscms_main']['css'];
    template::setCss("/templates/bartels/$css");
} else {
    template::setCss("/templates/bartels/common.css");
}
template::setCss('/templates/bartels/gallery/style.css?version=10', 1);
echo template::getCss();




        include_model ('gallery');
        $galImg = new galleryImage();
        if (empty($galImg->fileId)){
            $image_url = $galImg->getRandomImageURL();
        } else {
            $show = $galImg->selectOne('gallery_file', 'id', $galImg->fileId);
            $image_url = "/files/gallery/" .
                         $show['gallery_id'] . '/' .
                         $show['file_name'];
         }



template::setJs("http://ajax.googleapis.com/ajax/libs/jquery/1.3/jquery.min.js");
template::setJs("http://ajax.googleapis.com/ajax/libs/jqueryui/1.7.2/jquery-ui.js");
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
</head>
<body>
<div id="background">
    <img id="background" src="<?php echo $image_url ;?>" />
</div>
<div id="page">
    <div id="header">
        <?php if (empty(register::$vars['coscms_main']['logo'])) { ?>
            <div id ="logo_title"><h3><a href="/"><?php echo $_SERVER['HTTP_HOST']?></a></h3></div><?php
        } else { ?>
            <div id = "logo_img"><a href="/"><img width ="48%" alt="<?php echo $_SERVER['HTTP_HOST']?>" src="/logo/<?=register::$vars['coscms_main']['logo']?>" /></a></div><?php
        } ?>
        <div id ="top_blocks">
<?php

$blocks = layout::getTopBlocks();
foreach ($blocks as $key => $val){
    print $val;
}

?>
        </div>
    </div>

    <div id="sidebar_cheat">&nbsp;</div>
    <div id="sidebar_left">
<?php

$blocks = layout::getBlocks();
foreach ($blocks as $key => $val){
    print $val;
}

?>
    </div>
    <!--<div id="sidebar_right">
        <?php
        /**
        $blocks_sec = layout::getBlocksSec();
        foreach ($blocks_sec as $key => $val){
            print $val;
        }
        */

        ?>
   </div>-->
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
