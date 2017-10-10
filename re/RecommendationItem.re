open ReactNative;

module Style = {
  open ReactNative.Style;
  let content = style [height 215.];
  let container = style [height 555., backgroundColor Colors.white];
  let image = style [height 250., width (float_of_int Theme.width), backgroundColor "green"];
  let title = style [fontSize 26.];
};

let component = ReasonReact.statelessComponent "RecommendationItem";

let make ::id ::title ::description ::rating _children => {
  ...component,
  render: fun _self =>
    <View style=Style.container>
      <View style=Style.content>
        <Image
          source=Image.(Required (Packager.require "../../../assets/images/montserrat.png"))
          resizeMode=`contain
          style=Style.image
        />
        <Text style=Style.title> (ReasonReact.stringToElement title) </Text>
      </View>
    </View>
};
