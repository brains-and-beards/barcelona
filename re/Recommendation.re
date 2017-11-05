type place = {
  title: string,
  rating: int,
  description: string,
  image: ReactNative.Image.imageSource,
  category: Category.category
};

let recommendations = [|
  {
    title: "Montserrat",
    description: "The holy church on top of the mountain is a wonderful place of worship and climbing. There are also cool via ferratas to visit...",
    image:
      ReactNative.Image.(
        Required(ReactNative.Packager.require("../../../assets/images/montserrat.png"))
      ),
    rating: 4,
    category: See
  },
  {
    title: "Sagrada Familia",
    description: "Templo Expiatorio de la Sagrada Familia ia a large unfinished Roman Catholic church in Barcelona, designed by Catalan architect Antoni Gaudí...",
    image:
      ReactNative.Image.(
        Required(ReactNative.Packager.require("../../../assets/images/sagrada-familia.jpg"))
      ),
    rating: 3,
    category: See
  },
  {
    title: "Boqueria",
    description: "From December 1470 onwards, a pig market was held at this site; at this time it was known as Mercadi Bornet. Later, until 1794, it was known...",
    image:
      ReactNative.Image.(
        Required(ReactNative.Packager.require("../../../assets/images/boqueria.jpg"))
      ),
    rating: 2,
    category: See
  },
  {
    title: "Santa Ceviche",
    description: "Uno de los mejores restaurantes de comida peruana. Empezar con los choricitos, seguir con un buen ceviche y por último una jalea...",
    image:
      ReactNative.Image.(
        Required(ReactNative.Packager.require("../../../assets/images/santa-ceviche.jpg"))
      ),
    rating: 5,
    category: Eat
  },
  {
    title: "Quimet & Quimet",
    description: "Contemporary tapas menu with unusual and imaginative combinations of ingredients. Take for example the montadito: smoked salmon, Greek yogurt and truffled honey...",
    image:
      ReactNative.Image.(
        Required(ReactNative.Packager.require("../../../assets/images/quimet-quimet.jpg"))
      ),
    rating: 3,
    category: Eat
  },
  {
    title: "Bar La Plata",
    description: "Very cosy small local restaurant. They don't have enough seats. Ready to eat while standing. They do same 5 tapas since 1945....",
    image:
      ReactNative.Image.(
        Required(ReactNative.Packager.require("../../../assets/images/bar-la-plata.jpg"))
      ),
    rating: 3,
    category: Eat
  }
|];

let filteredRecommendations = (filter) =>
  Array.of_list(
    List.filter(
      (place) => filter == Category.All || filter == Category(place.category),
      Array.to_list(recommendations)
    )
  );
