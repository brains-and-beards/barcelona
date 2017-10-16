open ReactNative;

module Style = {
  open ReactNative.Style;
  let content = style [height 215.];
  let container = style [height 555., backgroundColor Colors.white];
  let image = style [height 250., width (float_of_int Theme.width), backgroundColor "green"];
  let title =
    style [
      height 85.,
      borderTopWidth 25.,
      borderTopColor Colors.black,
      backgroundColor Colors.brainsYellow,
      alignItems `flexStart,
      justifyContent `center,
      fontSize 28.
    ];
};

let component = ReasonReact.statelessComponent "RecommendationItem";

let make ::title ::description ::rating _children => {
  ...component,
  render: fun _self =>
    <View style=Style.container>
      <View style=Style.content>
        <Image
          source=Image.(Required (Packager.require "../../../assets/images/montserrat.png"))
          resizeMode=`contain
          style=Style.image
        />
        <CustomText style=Style.title> title </CustomText>
      </View>
    </View>
};
